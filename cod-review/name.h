#ifndef NAME_H_
#define NAME_H_

#include <optional>
#include <string>

class Name {
 public:
  Name(std::optional<std::string> surname,
       std::optional<std::string> first_name,
       std::optional<std::string> middle_name);

  std::string ToString() const;
  static bool IsValidName(const std::string& name);

  std::optional<std::string> GetSurname() const;
  std::optional<std::string> GetFirstName() const;
  std::optional<std::string> GetMiddleName() const;

 private:
  std::optional<std::string> surname_;
  std::optional<std::string> first_name_;
  std::optional<std::string> middle_name_;
};

#endif  // NAME_H_
