//
// Created by 杨凡 on 2022/2/24.
//

#ifndef COMPAREDIFFERENCE_FILECOMPARE_H
#define COMPAREDIFFERENCE_FILECOMPARE_H

#include<string>
#include<cstdlib>
#include "errorLog.h"

//策略模式，可以灵活扩展和变更策略
class strategy {
public:
    virtual std::string getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) = 0;

    virtual ~strategy() = default;
};

//整型策略
class intStrategy : public strategy {
public:
    std::string getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) override;
};

//浮点型策略
class doubleStrategy : public strategy {
public:
    std::string getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) override;
};

//字符串策略
class strStrategy : public strategy {
public:
    std::string getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) override;
};

//日期策略
class dateStrategy : public strategy {
public:
    std::string getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) override;
};

//专用于日期的处理
class date {
public:
    bool parse(const std::string &s);

    long operator-(const date &rightValue) const;

    bool isLeapYear() const;

    static std::string dayToString(long day);

private:
    long year_, month_, day_;
};

//策略模式的统一接口
class dataCompare {
public:
    explicit dataCompare(const std::string &dataType, const errorLog &log);

    explicit dataCompare(strategy *compareStrategy);

    static bool dataCheck(const std::string &dataType);

    std::string executeCompare(std::string dataToCompareLeft, std::string dataToCompareRight);

    ~dataCompare();

private:
    dataCompare() = default;//防止log未初始化就调用

    strategy *compareStrategy = nullptr;
    errorLog *log = nullptr;
};

#endif //COMPAREDIFFERENCE_FILECOMPARE_H
