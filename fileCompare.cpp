//
// Created by 杨凡 on 2022/2/24.
//

#include "fileCompare.h"

std::string intStrategy::getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) {//整型数据计算差异
    if (dataToCompareLeft == dataToCompareRight && dataToCompareLeft.length() == 0) {//空行直接返回
        return dataToCompareLeft;
    }
    char *stopLeft, *stopRight;
    std::string res = std::to_string(
            strtol(dataToCompareLeft.c_str(), &stopLeft, 10) - strtol(dataToCompareRight.c_str(), &stopRight, 10));
    if (strlen(stopLeft) == 0 && strlen(stopRight) == 0) {
        return res;
    } else {//不符合整型数据规则，转换失败
        std::cerr << "Error Flag: fail to get input int data difference! " +
                     std::string("Error Info: left value: ").append(dataToCompareLeft).append(", right value: ").append(
                             dataToCompareRight) << std::endl;
        return wrongRes;
    }
}

std::string doubleStrategy::getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) {//浮点型计算差异
    if (dataToCompareLeft == dataToCompareRight && dataToCompareLeft.length() == 0) {//空行直接返回
        return dataToCompareLeft;
    }
    char *stopLeft, *stopRight;
    std::string res = std::to_string(
            strtod(dataToCompareLeft.c_str(), &stopLeft) - strtod(dataToCompareRight.c_str(), &stopRight));
    if (strlen(stopLeft) == 0 && strlen(stopRight) == 0) {
        return res;
    } else {//不符合浮点型数据规则，转换失败
        std::cerr << "Error Flag: fail to get input double data difference! " +
                     std::string("Error Info: left value: ").append(dataToCompareLeft).append(", right value: ").append(
                             dataToCompareRight) << std::endl;
        return wrongRes;
    }
}

std::string strStrategy::getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) {//字符串数据计算差异
    if (dataToCompareLeft == dataToCompareRight && dataToCompareLeft.length() == 0) {//空行直接返回
        return dataToCompareLeft;
    }
    return dataToCompareLeft == dataToCompareRight ? "T" : "N";
}

std::string dateStrategy::getDiff(std::string dataToCompareLeft, std::string dataToCompareRight) {//日期数据计算差异
    if (dataToCompareLeft == dataToCompareRight && dataToCompareLeft.length() == 0) {//空行直接返回
        return dataToCompareLeft;
    }
    date *dateLeft = new date();
    date *dateRight = new date();
    if (!(dateLeft->parse(dataToCompareLeft) && dateRight->parse(dataToCompareRight))) {//日期解析
        std::cerr << "Error Flag: fail to get input date data difference! " +
                     std::string("Error Info: left value: ").append(dataToCompareLeft).append(", right value: ").append(
                             dataToCompareRight) << std::endl;
        return wrongRes;//格式不符合要求，转换失败
    }
    return date::dayToString(*dateLeft - *dateRight);
}

//策略模式核心
dataCompare::dataCompare(const std::string &dataType, const errorLog &log) {
    this->log = new errorLog(log);
    if (dataType.find("Int_") != -1) {
        compareStrategy = new intStrategy();
    } else if (dataType.find("Double_") != -1) {
        compareStrategy = new doubleStrategy();
    } else if (dataType.find("Str_") != -1) {
        compareStrategy = new strStrategy();
    } else if (dataType.find("Date_") != -1) {
        compareStrategy = new dateStrategy();
    } else {//其他数据类型，无法支持
        this->log->log("invalid data type", "data type: " + dataType + "!");
    }
}

//策略执行
std::string dataCompare::executeCompare(std::string dataToCompareLeft, std::string dataToCompareRight) {
    return compareStrategy->getDiff(std::move(dataToCompareLeft), std::move(dataToCompareRight));
}

//预留的接口，灵活变更策略
dataCompare::dataCompare(strategy *compareStrategy) {
    this->compareStrategy = compareStrategy;
}

//析构函数
dataCompare::~dataCompare() {
    delete compareStrategy;
    delete log;
}

//数据类型检查，防止出现非法数据类型
bool dataCompare::dataCheck(const std::string &dataType) {
    if (dataType.find("Int_") != -1 || dataType.find("Double_") != -1 ||
        dataType.find("Str_") != -1 || dataType.find("Date_") != -1) {
        return true;
    }
    return false;
}

//日期数据解析
bool date::parse(const std::string &s) {

    std::size_t firstPos = s.find('-');
    std::size_t lastPos = s.find_last_of('-');

    if (!(firstPos != lastPos && firstPos < s.length() && lastPos < s.length() && firstPos >= 0 && lastPos >= 0)) {
        return false;
    }

    char *stop;

    year_ = strtol(s.substr(0, firstPos).c_str(), &stop, 10);
    if (strlen(stop)) {
        return false;
    }
    month_ = strtol(s.substr(firstPos + 1, lastPos - firstPos - 1).c_str(), &stop, 10);
    if (strlen(stop)) {
        return false;
    }
    day_ = strtol(s.substr(lastPos + 1, s.length()).c_str(), &stop, 10);
    if (strlen(stop)) {
        return false;
    }
    return true;
}

//判断是否是闰年
bool date::isLeapYear() const {
    if (year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0) {
        return true;
    }
    return false;
}

//运算符重载，计算日期差
long date::operator-(const date &rightValue) const {
    long sumDay = 0;
    if (isLeapYear()) {//左操作数到年底的天数
        sumDay += 366 - ((month_ - 1) * 30 + day_ + (month_ > 3 ? month_ / 2 : month_ & 1 ? 0 : 1));
    } else {
        sumDay += 365 - ((month_ - 1) * 30 + day_ + (month_ > 3 ? month_ / 2 - 1 : month_ & 1 ? -1 : 1));
    }
    if (rightValue.isLeapYear()) {//右操作数从开年算起的天数
        sumDay += (month_ - 1) * 30 + day_ + (month_ > 3 ? month_ / 2 : month_ & 1 ? 0 : 1);
    } else {
        sumDay += (month_ - 1) * 30 + day_ + (month_ > 3 ? month_ / 2 - 1 : month_ & 1 ? -1 : 1);
    }
    sumDay += (rightValue.year_ - year_ - 1) * 365;//不算闰年，经过年数换算的时间
    sumDay += ((rightValue.year_ - 1) / 4 - (rightValue.year_ - 1) / 100 + (rightValue.year_ - 1) / 400) -
              (year_ / 4 - year_ / 100 + year_ / 400);//    容斥计算闰年时间
    return sumDay;
}

//差异天数转为字符串
std::string date::dayToString(long day) {
    return std::to_string(day);
}
