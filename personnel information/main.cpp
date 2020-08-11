#include "iostream"
#include "locale"
#include "fstream"
#include "string"
#include "json/json.h"

Json::Value jroot;
Json::Reader jsr;
Json::StyledWriter jsw;

void ls() {
    std::cout << "\t\t*********************\t\t" << std::endl;
    std::cout << "\t\tPERSONNEL INFORMATION\t\t" << std::endl;
    std::cout << "\t\t*********************\t\t" << std::endl;
    std::cout << jsw.write(jroot) << std::endl;
    std::cout << std::endl;
}

void add(std::string id, std::string name, std::string mobile, std::string etc) {
    /*if(jroot.find()){
        std::cout<<"the member is existed: id = "<<id<<"."<<std::endl;
        return;
    }*/
    Json::Value member;
    member["name"] = name;
    member["mobile"] = mobile;
    member["etc"] = etc;
    jroot[id] = member;
    std::wcout << "  adding guy successfully." << std::endl;
}

void del(std::string id) {
    jroot.removeMember(id);
    std::cout << "  this bastard has been slain ;)" << std::endl;
//    std::cout<<"the member is not existed: id = "<<id<<"."<<std::endl;
}

int main() {

    JSONCPP_STRING errs;
    Json::CharReaderBuilder rbuilder;
    Json::StreamWriterBuilder wbuilder;
    const std::unique_ptr<Json::StreamWriter> writer(wbuilder.newStreamWriter());
    std::string path = "/mnt/c/Users/Rend/desktop/智锐/职工信息/employee information.json";
    std::cout << "\n\t****************************************************" << std::endl;
    std::cout << "\t Hi! Which bitch you wanna find for playing today? ;)" << std::endl;
    std::cout << "\t****************************************************\n" << std::endl;

    std::ifstream ifs;
    std::ofstream ofs;
    ifs.open(path);
    {
        if (!ifs.is_open()) {
            std::cout << "  launching failed, can not find path of [employee information.json]!";
            return 0;
        }
        if (!parseFromStream(rbuilder, ifs, &jroot, &errs)) {
            std::cout << "  initial failed when loading jsonfile!\n";
            std::cout << "  " << errs << std::endl;
            return EXIT_FAILURE;
        }
    }
    ifs.close();

    ofs.open(path);

    std::cout << "  initial [employee information.json] successfully.\n";

    while (true) {
        std::string str, name, id, mobile, etc;
        std::cout << "<<";
        std::cin >> str;

        if (str == "ls") {
            ls();
        } else if (str == "add") {
            std::cout << "  press the ass' [name], [id], [mobile number], [etc] by space divided." << std::endl;
            std::cin >> name >> id >> mobile >> etc;
            add(id, name, mobile, etc);
            writer->write(jroot, &ofs);
        } else if (str == "del") {
            std::cout << "  press ass' [id] you wanna lick." << std::endl;
            std::cin >> id;
            del(id);
            writer->write(jroot, &ofs);
        } else if (str == "help") {
            std::cout << "\t\tManual of this shit personnel information system\t\t" << std::endl
                      << "\t\t----add: add a member" << std::endl
                      << "\t\t----del: delete a member" << std::endl
                      << "\t\t----ls: show all members" << std::endl
                      << "\t\t----exit: make a demon lick your ass " << std::endl;
        } else if (str == "exit") {
            writer->write(jroot, &ofs);
            break;
        } else
            std::cout << "  what damn wanna do you ass? ;(" << std::endl;
    }

    return EXIT_SUCCESS;
}