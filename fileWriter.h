//
// Created by 杨凡 on 2022/2/24.
//

#ifndef COMPAREDIFFERENCE_FILEWRITER_H
#define COMPAREDIFFERENCE_FILEWRITER_H

#include<string>
#include<fstream>
#include<ctime>
#include "errorLog.h"

//适配器模式
//文件写入基类
class fileWriter {
public:
    virtual bool dataWrite(std::ofstream &filePoint, std::string dataToWrite) = 0;

    virtual ~fileWriter() = default;
};

//拓展的文件写入基类
class advanceFileWriter {
public:
    virtual bool dataWrite(std::ofstream &filePoint, std::string dataToWrite) = 0;

    virtual  ~advanceFileWriter() = default;
};

//csv文件写入
class csvFileWriter : public advanceFileWriter {
public:
    bool dataWrite(std::ofstream &filePoint, std::string dataToWrite) override;
};

//database文件写入
class databaseFileWriter : public advanceFileWriter {
public:
    bool dataWrite(std::ofstream &filePoint, std::string dataToWrite) override;
};

//拓展的适配器
class dataWriteAdapter : public fileWriter {
public:

    explicit dataWriteAdapter(const std::string &filename);

    bool dataWrite(std::ofstream &filePoint, std::string dataToWrite) override;

    ~dataWriteAdapter() override;

private:

    advanceFileWriter *writeAdapter = nullptr;

};

//写入总接口，子类
class dataWriter : public fileWriter {
public:
    dataWriter(const std::string &filename, const errorLog &log);

    bool dataWrite(std::ofstream &filePoint, std::string dataToWrite) override;

    static bool fileCheck(const std::string &filename);

    bool dataOutput(std::string dataToWrite);

    ~dataWriter() override;

private:

    dataWriter() = default;//防止log未初始化就调用

    std::ofstream filePoint;
    std::string fileName;
    dataWriteAdapter *writeAdapter = nullptr;
    errorLog *log = nullptr;
};


#endif //COMPAREDIFFERENCE_FILEWRITER_H
