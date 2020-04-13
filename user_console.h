#ifndef PROG__USER_CONSOLE_H_
#define PROG__USER_CONSOLE_H_

#include <string>

namespace autocompleter {

class UserConsole {
 public:
  struct Request {
   public:
    enum class RequestType {
      AddText,
      Request,
      AddLetters
    };
    Request(RequestType request_type, std::string request_string);
    RequestType GetType() const;
    std::string& GetString();
   private:
    std::string string_;
    RequestType type_;
  };

  UserConsole();
  Request GetRequest();
  void WriteHint(const std::string& s);
};

}

#endif //PROG__USER_CONSOLE_H_
