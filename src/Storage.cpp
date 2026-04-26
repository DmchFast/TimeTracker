#include "Storage.h"

Storage *Storage::instance = nullptr;

Storage::Storage(const std::string &fname) : filename(fname) {}

Storage *Storage::getInstance(const std::string &fname)
{
   if (!instance)
      instance = new Storage(fname);
   return instance;
}

void Storage::save(const std::vector<Task> &tasks, const Task *activeTask)
{
   //TODO: запись в JSON
}

std::vector<Task> Storage::load(Task *&activeTask)
{
   activeTask = nullptr;
   return {};
}