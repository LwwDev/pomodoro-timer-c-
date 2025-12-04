#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

void Menu();
// void startTimer while timer is ongoing give option to stop end continue etc
// break short/long
// Exit
//
void startTimer();
void Clear();

int main() {
  Menu();

  return 0;
}

void Menu() {
  bool stop = false;
  while (!stop) {
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
      startTimer();
      break;
    case 3:
      std::cout << "Exiting program...";
      return;
      break;

    default:
      std::cout << "pick something from the menu please\n\n";
      break;
    }
  }
}
void startTimer() {
  int minutes = 25;
  std::cout << "Pomodoro timer started for " << minutes << " minutes!\n";

  for (int i = minutes * 60; i > 0; i--) {
    int min = i / 60;
    int sec = i % 60;
    std::cout << "\r" << min << "m " << sec << "s remaning " << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << "\nTime's up! Take a break!\n";
}
