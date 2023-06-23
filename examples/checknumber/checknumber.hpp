#ifndef CHECKNUMBER_HPP_INCLUDED
#define CHECKNUMBER_HPP_INCLUDED

#include <iostream>
#include <tinyfsm.hpp>

/***
State
   STATE_INITIAL,
   STATE_INT_SIGN,
   STATE_INTEGER,
   STATE_POINT,
   STATE_POINT_WITHOUT_INT,
   STATE_FRACTION,
   STATE_EXP,
   STATE_EXP_SIGN,
   STATE_EXP_NUMBER,
   STATE_END
*/

/**
 * CharType
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL
 *
 */

/* space * sign * integer * point * fraction * endspace */
/* space * sign * integer *  exp  * integer  * endspace */

struct InputIllegalEvent : tinyfsm::Event {};  // CHAR_ILLEGAL

struct InputNumberEvent : tinyfsm::Event {};  // CHAR_NUMBER

struct InputExpEvent : tinyfsm::Event {};  // CHAR_EXP

struct InputPointEvent : tinyfsm::Event {};  // CHAR_POINT

struct InputSpaceEvent : tinyfsm::Event {};  // CHAR_SPACE

struct InputSignEvent : tinyfsm::Event {};  // CHAR_SIGN

class CheckNumber : public tinyfsm::Fsm<CheckNumber> {
  /* NOTE: react(), entry() and exit() functions need to be accessible
   * from tinyfsm::Fsm class. You might as well declare friendship to
   * tinyfsm::Fsm, and make these functions private:
   *
   * friend class Fsm;
   */
 public:
  /* default reaction for unhandled events */
  void react(tinyfsm::Event const &){};
  virtual void react(InputIllegalEvent const &);
  virtual void react(InputNumberEvent const &);
  virtual void react(InputExpEvent const &);
  virtual void react(InputSpaceEvent const &);
  virtual void react(InputPointEvent const &);
  virtual void react(InputSignEvent const &);

  virtual std::string get_state() { return "Base class"; };

  virtual void entry(void){}; /* entry actions in some states */
  void exit(void){};          /* no exit actions at all */

 protected:
};

#endif  // CHECKNUMBER_HPP_INCLUDED
