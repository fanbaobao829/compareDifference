#include "fileReader.h"
#include "fileCompare.h"
#include "fileWriter.h"
#include "errorLog.h"

int main(int argc, char *argv[]) {

    auto *globalLog = new errorLog();//选择是否输出日志到控制台或者文件

    if (argc != 4) {//参数必须为3个
        globalLog->log("input parameter error",
                       "Expected number of input parameters: 3, Number of actual input parameters: " +
                       std::to_string(argc) + ".");
        delete globalLog;
        return 0;
    }
    //工厂模式
    auto *inputFilefactory = new fileReaderFactory(*globalLog);

    fileReader *inputFile_1 = inputFilefactory->getFileReader(argv[1]);//输入文件读取

    if (!inputFile_1) {//文件读取失败
        globalLog->log("Failed to open input file left", "Open input filename: " + std::string(argv[1]));
        delete globalLog;
        delete inputFile_1;
        return 0;
    }

    if (inputFile_1->getDataType().empty()) {//获取数据类型失败
        globalLog->log("Failed to get input file left data Type", "Open input filename: " + std::string(argv[1]));
        delete globalLog;
        delete inputFile_1;
        return 0;
    }

    fileReader *inputFile_2 = inputFilefactory->getFileReader(argv[2]);//输入文件读取

    if (!inputFile_2) {//文件读取失败
        globalLog->log("Failed to open input file right", "Open input filename: " + std::string(argv[2]));
        delete globalLog;
        delete inputFile_1;
        delete inputFile_2;
        return 0;
    }

    if (inputFile_2->getDataType().empty()) {//获取数据类型失败
        globalLog->log("Failed to get input file right data Type", "Open input filename: " + std::string(argv[2]));
        delete globalLog;
        delete inputFile_1;
        delete inputFile_2;
        return 0;
    }

    if (inputFile_1->getDataType() != inputFile_2->getDataType()) {//两个文件的数据类型不一致
        globalLog->log("Inconsistent file data type",
                       "left data Type: " + inputFile_1->getDataType() + ", right data Type: " +
                       inputFile_2->getDataType() + " !");
        delete globalLog;
        delete inputFile_1;
        delete inputFile_2;
        return 0;
    }

    if (!dataCompare::dataCheck(inputFile_1->getDataType())) {//文件数据类型检查，仅支持txt、csv和db类型
        globalLog->log("Invalid data type", "data Type: " + inputFile_1->getDataType() + " !");
        delete globalLog;
        delete inputFile_1;
        delete inputFile_2;
        return 0;
    }
    //策略模式
    auto *fileCompare = new dataCompare(inputFile_1->getDataType(), *globalLog);//文件内容对比

    if (!dataWriter::fileCheck(argv[3])) {//检查输出文件类型
        globalLog->log("Error Flag: Invalid output file type! ", "Error Info: file name: " + std::string(argv[3]));
    }
    //适配器模式
    auto *fileWriter = new dataWriter(argv[3], *globalLog);//输出内容到文件

    if (!fileWriter->dataOutput("Diff")) {//输出差异的标识"Diff"
        globalLog->log("Error Flag: fail output data tag! ", "Error Info: file name: " + std::string(argv[3]));
    }

    std::string file_input_1, file_input_2;//每次获取到的文件内容信息，用于对比

    while (inputFile_1->getFileLine(file_input_1) && inputFile_2->getFileLine(file_input_2)) {//获取输入文件数据
        std::string diffResStr = fileCompare->executeCompare(file_input_1, file_input_2);//内容对比，计算差异

        if (diffResStr == wrongRes) {//输入内容错误，与类型不符
            globalLog->log("Error Flag: fail to get input data difference! ",
                           std::string("Error Info: left value: ").append(file_input_1).append(
                                   ", right value: ").append(file_input_2));
            break;
        }

        if (!fileWriter->dataOutput(diffResStr)) {//输出到文件失败
            globalLog->log("Error Flag: fail output data difference! ",
                           std::string("Error Info: left value: ").append(file_input_1).append(
                                   ", right value: ").append(file_input_2));
            break;
        }
    }

    //析构，释放内存
    delete inputFile_1;
    delete inputFile_2;
    delete inputFilefactory;
    delete fileCompare;
    delete fileWriter;
    delete globalLog;
    return 0;
}
