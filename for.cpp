#include <iostream>
#include <string>
using std::cout;

struct Stack {
  int val;
  Stack* prev = nullptr;
  Stack(int v) : val(v){};
};

Stack* cur_ptr = nullptr;
int stack_size = 0;

void Push(int value) {
  Stack* new_elem = new Stack(value);
  new_elem->prev = cur_ptr;
  cur_ptr = new_elem;
  ++stack_size;
  cout << "ok\n";
}

void Pop() {
  Stack* time_ptr = cur_ptr;
  cur_ptr = cur_ptr->prev;
  --stack_size;
  delete time_ptr;
}

void Back() {
  if (cur_ptr == nullptr) {
    cout << "error\n";
  } else {
    cout << cur_ptr->val << "\n";
  }
}

void Size() { cout << stack_size << "\n"; }

void Clear() {
  while (cur_ptr != nullptr) {
    Pop();
  }
  stack_size = 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string cmd;
  int num;
  while (std::cin >> cmd) {
    if (cmd == "push") {
      std::cin >> num;
      Push(num);
    } else if (cmd == "pop") {
      if (cur_ptr == nullptr) {
        cout << "error\n";
      } else {
        cout << cur_ptr->val << "\n";
        Pop();
      }
    } else if (cmd == "back") {
      Back();
    } else if (cmd == "size") {
      Size();
    } else if (cmd == "clear") {
      Clear();
      cout << "ok\n";
    } else if (cmd == "exit") {
      std::cout << "bye\n";
      Clear();
      break;
    }
  }
}
