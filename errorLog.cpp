//
// Created by 杨凡 on 2022/2/25.
//

#include "errorLog.h"

#include <utility>


//类似工厂模式，主要用于日志打印
errorLog::errorLog(const std::string &filename) {//构造函数，到文件
    if (errLog != nullptr) {
        errLog->outputErrorMessage("Create Log repeatedly for file: " + filename + " !",
                                   "Create Log repeatedly, keep the original log！");
        return;
    }
    errLog = new fileLog(filename);
    fileName = filename;
}

errorLog::errorLog() {//构造函数，到控制台
    if (errLog != nullptr) {

        errLog->outputErrorMessage("Create Log repeatedly for ostream!",
                                   "Create Log repeatedly, keep the original log！");
        return;
    }
    errLog = new cerrLog();
}

void errorLog::log(std::string flag, std::string info) {//日志打印接口
    errLog->outputErrorMessage(std::move(flag), std::move(info));
}

errorLog::~errorLog() {//析构函数
    delete errLog;
}

errorLog::errorLog(const errorLog &log) {//拷贝构造
    if (fileName.length()) {
        errLog = new fileLog(fileName);
    } else {
        errLog = new cerrLog();
    }
}

fileLog::fileLog(const std::string &fileName) {//构造函数，输出到文件
    errOutput.open(fileName);
    if (!errOutput.is_open()) {
        std::cerr
                << "Error Flag: Create Log fail! Error Info: Create Log fail for file: " + fileName +
                   "!" << std::endl;
    }
}

void fileLog::outputErrorMessage(std::string flag, std::string info) {//输出到文件
    errOutput << "Error Flag: " << flag << ", Error Info: " << info << std::endl;
}

fileLog::~fileLog() {//析构函数
    errOutput.close();
}

void cerrLog::outputErrorMessage(std::string flag, std::string info) {//输出到控制台
    std::cerr << "Error Flag: " << flag << ", Error Info: " << info << std::endl;
}
