#include "solution.hpp"

using namespace std;

Student ReadStudentRecFromStream(std::istream& file) {
  string full_name;
  unsigned int uin = 0;
  double gpa = 0.0;
  string last;
  string uins;
  string gpas;

  file >> full_name >> last >> uins >> gpas;

  if (last[last.size() - 1] != ',') return Student{};
  last.erase(last.size() - 1);
  full_name += " " + last;

  if (uins[uins.size() - 1] != ',') return Student{};
  try {
    uins.erase(uins.size() - 1);
    uin = stoi(uins);
    gpa = stoi(gpas);
  } catch (...) {
    return Student{};
  }

  return Student{full_name, uin, gpa};
}