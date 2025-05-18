#include "human.h"

Human::Human(const Name& name, int height,
             std::optional<Human*> father)
    : name_(name), height_(height), father_(father) {
  UpdateName();
}

void Human::UpdateName() {
  if (!name_.GetSurname() && father_ && (*father_)->name_.GetSurname()) {
    name_ = Name((*father_)->name_.GetSurname(), name_.GetFirstName(),
                 name_.GetMiddleName());
  }
  if (!name_.GetMiddleName() && father_ && (*father_)->name_.GetFirstName()) {
    std::string fn = *(*father_)->name_.GetFirstName();
    name_ = Name(name_.GetSurname(), name_.GetFirstName(), fn + "ович");
  }
}

std::string Human::ToString() const {
  return name_.ToString() + " и ростом " + std::to_string(height_);
}
