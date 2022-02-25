//
// Created by 杨凡 on 2022/2/24.
//

#include "fileWriter.h"

//适配器模式
bool csvFileWriter::dataWrite(std::ofstream &filePoint, std::string dataToWrite) {//写入csv文件单行内容
    if (filePoint << dataToWrite << std::endl) {
        return true;
    }
    return false;
}

bool databaseFileWriter::dataWrite(std::ofstream &filePoint, std::string dataToWrite) {//写入database文件单行内容
    if (filePoint << dataToWrite << std::endl) {
        return true;
    }
    return false;
}

dataWriteAdapter::dataWriteAdapter(const std::string &filename) {//适配器
    if (filename.rfind(".csv") != -1) {
        writeAdapter = new csvFileWriter();
    } else if (filename.rfind(".db") != -1) {
        writeAdapter = new databaseFileWriter();
    }
}

bool dataWriteAdapter::dataWrite(std::ofstream &filePoint, std::string dataToWrite) {//适配器写入文件内容
    return writeAdapter->dataWrite(filePoint, dataToWrite);
}

dataWriter::~dataWriter() {//数据写入的析构
    delete writeAdapter;
    delete log;
}

dataWriter::dataWriter(const std::string &filename, const errorLog &log) {//数据写入的构造

    this->log = new errorLog(log);

    filePoint.open(filename);

    if (!filePoint.is_open()) {
        std::cerr << "Error Flag: open output file fail! Error Info: open input file fail: " + filename + "!"
                  << std::endl;
    }

    if (filename.rfind(".csv") != -1 || filename.rfind(".db") != -1) {//通过适配器写入
        writeAdapter = new dataWriteAdapter(filename);
    }

    fileName = filename;
}

bool dataWriter::dataWrite(std::ofstream &unused_filePoint, std::string dataToWrite) {//数据写入
    if (fileName.rfind(".txt") != -1) {//不需要走适配器
        if (filePoint << dataToWrite << std::endl) {
            return true;
        } else {
            log->log("fail to output data for txt file! ", "Error Info: txt file name: " + fileName);
            return false;

        }
    } else if (fileName.rfind(".db") != -1 || fileName.rfind(".csv") != -1) {//适配器即可
        if (writeAdapter) {
            if (!writeAdapter->dataWrite(filePoint, dataToWrite)) {

                log->log("fail to output data for csv or database file! ",
                         "file name: " + fileName);
                return false;
            }
        } else {
            log->log("fail to output data for csv or database file, require writeAdapter! ",
                     "file name: " + fileName);
            return false;
        }
    }
    return true;
}

bool dataWriter::dataOutput(std::string dataToWrite) {//数据输出
    return dataWrite(filePoint, std::move(dataToWrite));
}

bool dataWriter::fileCheck(const std::string &filename) {//输出文件类型检查
    if (filename.rfind(".txt") != -1 || filename.rfind(".csv") != -1 || filename.rfind(".db") != -1) {
        return true;
    }
    return false;
}

dataWriteAdapter::~dataWriteAdapter() {//适配器析构
    delete this->writeAdapter;
}
