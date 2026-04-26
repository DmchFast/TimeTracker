#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "Task.h"

class Storage
{
public:
   //* экземпляр
   static Storage *getInstance(const std::string &fname = "data.json");
   void save(const std::vector<Task> &tasks, const Task *activeTask);
   std::vector<Task> load(Task *&activeTask);

private:
   Storage(const std::string &fname = "data.json"); //* приватный конструктор
   static Storage *instance;
   std::string filename;
};

#endif