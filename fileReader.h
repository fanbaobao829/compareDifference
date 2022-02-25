//
// Created by 杨凡 on 2022/2/24.
//

#ifndef COMPAREDIFFERENCE_FILEREADER_H
#define COMPAREDIFFERENCE_FILEREADER_H

#include<fstream>
#include<string>
#include<cstdio>
#include "errorLog.h"

//工厂模式

const int blockSize = 32;//读取database的单行最大长度

//基类
class fileReader {
public:
    virtual bool getFileLine(std::string &s) = 0;

    virtual std::string getDataType() = 0;

    virtual void delInvalidStr(std::string &s) = 0;

    virtual ~fileReader() = default;
};

//txt子类
class txtFileReader : public fileReader {
public:
    explicit txtFileReader(const std::string &filename);

    bool getFileLine(std::string &s) override;

    std::string getDataType() override;

    void delInvalidStr(std::string &s) override;

    ~txtFileReader() override;

private:
    std::ifstream filePointer;
    std::string dataType;
};

//csv子类
class csvFileReader : public fileReader {
public:
    explicit csvFileReader(const std::string &filename);

    bool getFileLine(std::string &s) override;

    std::string getDataType() override;

    void delInvalidStr(std::string &s) override;

    ~csvFileReader() override;

private:
    std::ifstream filePointer;
    std::string dataType;
};

//database子类
class databaseFileReader : public fileReader {
public:
    explicit databaseFileReader(const std::string &filename);

    bool getFileLine(std::string &s) override;

    std::string getDataType() override;

    void delInvalidStr(std::string &s) override;

    ~databaseFileReader() override;

private:
    FILE *filePointer = nullptr;
    std::string dataType;
};

//工厂类
class fileReaderFactory {
public:
    explicit fileReaderFactory(const errorLog &log);

    fileReader *getFileReader(const std::string &filename);

    ~fileReaderFactory();

private:
    fileReaderFactory() = default;//防止log未初始化就调用

    errorLog *log;
};

#endif //COMPAREDIFFERENCE_FILEREADER_H
