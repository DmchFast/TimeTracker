#include "TimeTracker.h"
#include <iostream>
#include <limits>

using namespace std;

TimeTracker::TimeTracker() : activeTask(nullptr)
{
   storage = Storage::getInstance("data.json");
}
TimeTracker::~TimeTracker() {}

void TimeTracker::clearScreen()
{
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void TimeTracker::waitForEnter()
{
   cout << "\nПодтвердить (enter)";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cin.get();
}

void TimeTracker::showMenu()
{
   clearScreen();
   cout << "~ TimeTracker ~\n";
   if (activeTask)
      cout << "Активная задача: " << activeTask->getName() << "\n";
   else
      cout << "Нет активной задачи.\n";
   cout << "\nМеню:\n";
   cout << "1. Все задачи\n2. Добавить задачу\n3. Редактировать задачу\n4. Удалить задачу\n";
   cout << "5. Запустить таймер\n6. Остановить таймер\n";
   cout << "7. Отчёт за сегодня\n8. Отчёт за период\n0. Выход\n> ";
}

void TimeTracker::showAllTasks() { cout << "Все задачи\n"; }
void TimeTracker::addNewTask() { cout << "Добавить задачу\n"; }
void TimeTracker::editTaskName() { cout << "Редактировать задачу\n"; }
void TimeTracker::deleteTaskById() { cout << "Удалить задачу\n"; }
void TimeTracker::startTimer() { cout << "Запуск таймера\n"; }
void TimeTracker::stopTimer() { cout << "Остановка таймера\n"; }
void TimeTracker::showDailyReport() { cout << "Отчёт за сегодня\n"; }
void TimeTracker::showPeriodReport() { cout << "Отчёт за период\n"; }

void TimeTracker::handleCommand(int choice)
{
   switch (choice)
   {
   case 1:
      showAllTasks();
      break;
   case 2:
      addNewTask();
      break;
   case 3:
      editTaskName();
      break;
   case 4:
      deleteTaskById();
      break;
   case 5:
      startTimer();
      break;
   case 6:
      stopTimer();
      break;
   case 7:
      showDailyReport();
      break;
   case 8:
      showPeriodReport();
      break;
   case 0:
      break;
   default:
      cout << "Неверный пункт.\n";
   }
   if (choice != 0 && choice != 5 && choice != 6)
      waitForEnter();
}

void TimeTracker::run()
{
   int choice;
   do
   {
      showMenu();
      cin >> choice;
      handleCommand(choice);
   } while (choice != 0);
}