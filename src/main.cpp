#include <clocale>
#include "TimeTracker.h"

using namespace std;

int main()
{
   setlocale(LC_ALL, ".UTF-8");
   TimeTracker app;
   app.run();
   return 0;
}