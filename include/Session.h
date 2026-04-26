#ifndef SESSION_H
#define SESSION_H

#include <chrono>
#include <string>

class Session
{
public:
   Session();
   void stop();
   long long getDuration() const;
   bool isFinished() const;
   //* методы для сериализации (JSON)
   std::string getStartTimeStr() const;
   std::string getEndTimeStr() const;
   void setStartTime(const std::string &str);
   void setEndTime(const std::string &str);

private:
   std::chrono::system_clock::time_point startTime;
   std::chrono::system_clock::time_point endTime;
   bool isActive; //* остановка сессии
};

#endif