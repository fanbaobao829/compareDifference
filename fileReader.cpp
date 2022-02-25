//
// Created by 杨凡 on 2022/2/24.
//

#include "fileReader.h"

txtFileReader::txtFileReader(const std::string &filename) {//txt读取构造函数
    filePointer.open(filename);
    if (!filePointer.is_open()) {//打开失败
        std::cerr
                << "Error Flag: open input file txt fail! Error Info: open input file fail: " + filename +
                   "!" << std::endl;
    }
}

bool txtFileReader::getFileLine(std::string &s) {//txt文件读取下一行
    if (getline(filePointer, s)) {
        delInvalidStr(s);//去除无效字符
        return true;
    }
    return false;//表示获取失败
}

txtFileReader::~txtFileReader() {//txt读取的析构
    filePointer.close();
}

std::string txtFileReader::getDataType() {//获取txt文件的数据类型
    if (!dataType.empty()) {
        return dataType;
    }
    if (getline(filePointer, dataType)) {
        return dataType;
    }
    std::cerr
            << "Error Flag: get input data type fail! Error Info: open input file txt fail!" << std::endl;
    return dataType = "";
}

void txtFileReader::delInvalidStr(std::string &s) {//移除txt多余无效字符
    if (s.empty()) {
        return;
    }

    s.erase(0, s.find_first_not_of(" \n\r"));//认为换行和回车都是无效字符
    s.erase(s.find_last_not_of(" \n\r") + 1);
}

csvFileReader::csvFileReader(const std::string &filename) {//读取csv文件数据
    filePointer.open(filename);
    if (!filePointer.is_open()) {//打开失败
        std::cerr
                << "Error Flag: open input file csv fail! Error Info: open input file fail: " + filename +
                   "!" << std::endl;
    }
}

bool csvFileReader::getFileLine(std::string &s) {//获取csv文件的下一行
    if (getline(filePointer, s)) {
        delInvalidStr(s);//移除无效字符
        return true;
    }
    return false;
}

csvFileReader::~csvFileReader() {//csv读取的析构
    filePointer.close();
}

std::string csvFileReader::getDataType() {//获取csv文件的内容数据类型
    if (!dataType.empty()) {
        return dataType;
    }
    if (getline(filePointer, dataType)) {
        return dataType;
    }
    std::cerr
            << "Error Flag: get input data type fail! Error Info: open input file csv fail!" << std::endl;
    return dataType = "";
}

void csvFileReader::delInvalidStr(std::string &s) {//移除csv多余无效字符
    if (s.empty()) {
        return;
    }

    s.erase(0, s.find_first_not_of(" \n\r"));
    s.erase(s.find_last_not_of(" \n\r") + 1);
}

databaseFileReader::databaseFileReader(const std::string &filename) {//读取database数据
    filePointer = fopen(filename.c_str(), "r");
    if (!filePointer) {//打开失败
        std::cerr
                << "Error Flag: open input file database fail! Error Info: open input file fail: " + filename +
                   "!" << std::endl;
    }
}

bool databaseFileReader::getFileLine(std::string &s) {//读取database的下一行
    char str[blockSize];
    if (fgets(str, blockSize, filePointer)) {
        if (str[strlen(str) - 1] != '\n' && str[strlen(str) - 1] != '\r') {//单行太长，不符合date的规格
            std::cerr
                    << "Error Flag: get input data line fail! Error Info: open input file database find data line too large!"
                    << std::endl;

            return false;
        }
        delInvalidStr(s = str);
        return true;
    }
    return false;
}

databaseFileReader::~databaseFileReader() {//database读取的析构
    fclose(filePointer);
}

std::string databaseFileReader::getDataType() {//读取database文件的内容数据类型
    if (!dataType.empty()) {
        return dataType;
    }
    char str[blockSize];
    if (fgets(str, blockSize, filePointer)) {
        if (str[strlen(str) - 1] != '\n' && str[strlen(str) - 1] != '\r') {//单行太长，不符合date的规格
            std::cerr
                    << "Error Flag: get input data type fail! Error Info: open input file database find data type too large!"
                    << std::endl;
        } else {
            return dataType = str;
        }
    }
    std::cerr
            << "Error Flag: get input data type fail! Error Info: open input file txt fail!" << std::endl;
    return dataType = "";
}

void databaseFileReader::delInvalidStr(std::string &s) {//移除database文件的无效字符
    if (s.empty()) {
        return;
    }

    s.erase(0, s.find_first_not_of(" \n\r"));
    s.erase(s.find_last_not_of(" \n\r") + 1);
}

fileReader *fileReaderFactory::getFileReader(const std::string &filename) {//工厂模式的核心
    if (filename.rfind(".txt") != -1) {//反向查找，加快效率
        return new txtFileReader(filename);
    } else if (filename.rfind(".csv") != -1) {
        return new csvFileReader(filename);
    } else if (filename.rfind(".db") != -1) {
        return new databaseFileReader(filename);
    } else {
        log->log("Undefined file type", "The currently tried file type is: " + filename);
        return nullptr;
    }
}

fileReaderFactory::~fileReaderFactory() {//工厂析构
    delete log;
}

fileReaderFactory::fileReaderFactory(const errorLog &log) {//工厂构造
    this->log = new errorLog(log);
}
