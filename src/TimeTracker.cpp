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
   cout << "1. Все задачи\n";
   cout << "2. Добавить задачу\n";
   cout << "3. Редактировать задачу\n";
   cout << "4. Удалить задачу\n";
   cout << "5. Запустить таймер\n";
   cout << "6. Остановить таймер\n";
   cout << "7. Отчёт за сегодня\n";
   cout << "8. Отчёт за период\n";
   cout << "0. Выход\n";
   cout << "> ";
}

void TimeTracker::showAllTasks()
{
   if (tasks.empty())
   {
      cout << "Список задач пока пуст.\n";
      return;
   }
   for (size_t i = 0; i < tasks.size(); ++i)
   {
      long long sec = tasks[i].totalDuration(); //* общее время в сек
      long long h = sec / 3600, m = (sec % 3600) / 60, s = sec % 60;
      cout << i + 1 << ". " << tasks[i].getName()
           << " (всего: " << h << "ч " << m << "м " << s << "с)\n";
   }
}

void TimeTracker::addNewTask()
{
   cout << "Название задачи: ";
   string name;
   cin.ignore(); //* очистка буфер перед getline
   getline(cin, name);
   if (name.empty())
   {
      cout << "Имя не может быть пустым.\n";
      return;
   }
   tasks.emplace_back(name); //* добавление задачи с именем
   cout << "Задача добавлена.\n";
}

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