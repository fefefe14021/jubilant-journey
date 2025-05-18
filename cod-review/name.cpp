#include "name.h"
#include <regex>

Name::Name(std::optional<std::string> surname,
           std::optional<std::string> first_name,
           std::optional<std::string> middle_name)
    : surname_(surname), first_name_(first_name), middle_name_(middle_name) {}

std::string Name::ToString() const {
  std::string result;
  if (surname_) result += *surname_ + " ";
  if (first_name_) result += *first_name_ + " ";
  if (middle_name_) result += *middle_name_;
  if (!result.empty() && result.back() == ' ') result.pop_back();
  return result;
}

bool Name::IsValidName(const std::string& name) {
  std::regex pattern("^[А-Яа-яA-Za-z ]+$");
  return !name.empty() && std::regex_match(name, pattern);
}

std::optional<std::string> Name::GetSurname() const { return surname_; }
std::optional<std::string> Name::GetFirstName() const { return first_name_; }
std::optional<std::string> Name::GetMiddleName() const { return middle_name_; }
