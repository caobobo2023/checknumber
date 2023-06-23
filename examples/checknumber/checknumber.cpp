#include "checknumber.hpp"

#include <iostream>

class state_initial;
class state_illegal;
class state_int_sign;
class state_integer;
class state_point;
class state_exp;
class state_fraction;
class state_end;

/*STATE_INITIAL*/
class state_initial : public CheckNumber {
  void entry() override { std::cout << "enter initial state" << std::endl; };
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override
  {
    transit<state_integer>();
    return;
  };

  void react(InputExpEvent const &) override
  {
    transit<state_exp>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_illegal>();
    return;
  }
  void react(InputSpaceEvent const &) override { return; };

  void react(InputSignEvent const &) override
  {
    transit<state_int_sign>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_INITIAL" << std::endl;
    return "STATE_INITIAL";
  };
};

/* STATE_INTEGER_SIGN*/
class state_int_sign : public CheckNumber {
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override
  {
    transit<state_integer>();

    return;
  };

  void react(InputExpEvent const &) override
  {
    transit<state_exp>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_illegal>();
    return;
  }
  void react(InputSpaceEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputSignEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_INTEGER_SIGN" << std::endl;
    return "STATE_INTEGER_SIGN";
  };
};

/* STATE_INTEGER,*/
class state_integer : public CheckNumber {
  void entry() override { std::cout << "enter integer state" << std::endl; };
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override { return; };

  void react(InputExpEvent const &) override
  {
    transit<state_exp>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_fraction>();
    return;
  }
  void react(InputSpaceEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputSignEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_INTEGER" << std::endl;
    return "STATE_INTEGER";
  };
};

/* STATE_POINT*/
class state_point : public CheckNumber {
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override
  {
    transit<state_fraction>();
    return;
  };

  void react(InputExpEvent const &) override
  {
    transit<state_illegal>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_illegal>();
    return;
  }
  void react(InputSpaceEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputSignEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_POINT" << std::endl;
    return "STATE_POINT";
  };
};

/* STATE_EXP*/
class state_exp : public CheckNumber {
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override
  {
    transit<state_exp>();
    return;
  };

  void react(InputExpEvent const &) override
  {
    transit<state_illegal>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_illegal>();
    return;
  }
  void react(InputSpaceEvent const &) override
  {
    transit<state_end>();
    return;
  };

  void react(InputSignEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_EXP" << std::endl;
    return "STATE_EXP";
  };
};

/* STATE_FRACTION*/
class state_fraction : public CheckNumber {
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override
  {
    transit<state_fraction>();
    return;
  };

  void react(InputExpEvent const &) override
  {
    transit<state_illegal>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_illegal>();
    return;
  }
  void react(InputSpaceEvent const &) override
  {
    transit<state_end>();
    return;
  };

  void react(InputSignEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_FRACTION" << std::endl;
    return "STATE_FRACTION";
  };
};

/* STATE_END*/
class state_end : public CheckNumber {
  void react(InputIllegalEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputNumberEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  void react(InputExpEvent const &) override
  {
    transit<state_illegal>();
    return;
  }

  void react(InputPointEvent const &) override
  {
    transit<state_illegal>();
    return;
  }
  void react(InputSpaceEvent const &) override
  {
    transit<state_end>();
    return;
  };

  void react(InputSignEvent const &) override
  {
    transit<state_illegal>();
    return;
  };

  std::string get_state() override
  {
    std::cout << "STATE_END" << std::endl;
    return "STATE_END";
  };
};

/*illegal*/
class state_illegal : public CheckNumber {
  void react(InputIllegalEvent const &) override { return; };

  void react(InputNumberEvent const &) override { return; };

  void react(InputExpEvent const &) override { return; }

  void react(InputPointEvent const &) override { return; }
  void react(InputSpaceEvent const &) override { return; };
  void react(InputSignEvent const &) override { return; };
  void entry() override
  {
    std::cout << "enter illegal state, stop" << std::endl;
  };

  std::string get_state() override
  {
    std::cout << "STATE_ILLEGAL" << std::endl;
    return "STATE_ILLEGAL";
  };
};

FSM_INITIAL_STATE(CheckNumber, state_initial)