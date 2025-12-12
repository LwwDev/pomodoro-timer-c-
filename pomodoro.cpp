#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

void Menu();
void startTimer(int minutes);
void takeBreak();

int main() {
  Menu();

  return 0;
}

void Menu() {
  bool stop = false;
  do {
    std::cout << "============================\n";
    std::cout << "====== Pomodoro Timer ======\n";
    std::cout << "============================\n\n";

    int menuChoice;
    std::cout << "1. start 25 min timer\n";
    std::cout << "2. take break\n";
    std::cout << "3. Exit\n\n";
    std::cin >> menuChoice;

    switch (menuChoice) {
    case 1:
      startTimer(25);
      break;
    case 2:
      takeBreak();
      break;
    case 3:
      std::cout << "Exiting program...";
      return;
      break;

    default:
      std::cout << "pick something from the menu please\n\n";
      break;
    }
  } while (!stop);
}

void takeBreak() {
  int breakChoice;
  std::cout << "How long break would you like to take?: \n\n"
            << "1. 5 minutes\n"
            << "2. 15 minutes\n"
            << "3. Custom time\n\n";
  std::cin >> breakChoice;

  switch (breakChoice) {
  case 1:
    startTimer(5);
    break;
  case 2:
    startTimer(15);
    break;
  case 3: {
    int custom;
    std::cout << "Choose custom time (minutes): \n";
    std::cin >> custom;
    startTimer(custom);
    break;
  }
  default:
    std::cout << "choose a valid option\n";
    break;
  }
}

void startTimer(int minutes) {
  std::cout << "Pomodoro timer started for " << minutes << " minutes!\n";

  for (int i = minutes * 60; i > 0; i--) {
    int min = i / 60;
    int sec = i % 60;
    std::cout << "\r" << min << "m " << sec << "s remaining " << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << "\nTime's up! Take a break!\n";
}
