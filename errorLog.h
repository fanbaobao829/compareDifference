//
// Created by 杨凡 on 2022/2/25.
//

#ifndef COMPAREDIFFERENCE_ERRORLOG_H
#define COMPAREDIFFERENCE_ERRORLOG_H

#include<string>
#include<iostream>
#include<fstream>
#include<cassert>

#define wrongRes "*+*+*"

//基类，可拓展
class Log {
public:
    virtual void outputErrorMessage(std::string flag, std::string info) = 0;

    virtual ~Log() = default;
};

//子类，到控制台的输出
class cerrLog : public Log {
public:
    void outputErrorMessage(std::string flag, std::string info) override;
};

//子类，到文件的输出
class fileLog : public Log {
public:
    explicit fileLog(const std::string &fileName);

    void outputErrorMessage(std::string flag, std::string info) override;

    ~fileLog() override;

private:
    std::fstream errOutput;
};

//统一接口，日志打印
class errorLog {
public:
    errorLog();

    errorLog(const errorLog &log);

    explicit errorLog(const std::string &filename);

    void log(std::string flag, std::string info);

    ~errorLog();

private:
    Log *errLog = nullptr;
    std::string fileName;
};


#endif //COMPAREDIFFERENCE_ERRORLOG_H
