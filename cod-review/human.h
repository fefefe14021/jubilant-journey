#ifndef HUMAN_H_
#define HUMAN_H_

#include <optional>
#include <string>
#include "name.h"

class Human {
 public:
  Human(const Name& name, int height,
        std::optional<Human*> father = std::nullopt);
  std::string ToString() const;

 private:
  void UpdateName();

  Name name_;
  int height_;
  std::optional<Human*> father_;
};

#endif  // HUMAN_H_
