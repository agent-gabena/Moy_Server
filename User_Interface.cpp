#include "User_Interface.h"
#include "Communicator.h"
User_Interface::User_Interface(int argc, char **argv) {
    descr.add_options()
        ("help,h" , "Помощь")
        ("file,f", po::value<std::string>(&file), "введите имя файла с базой клиентов")
        ("logwrite,l", po::value<std::string>(&LogWrite), "введите имя файла с журналом работы")
        ("port,p", po::value<int>(&port), "введите номер порта")
        ;
    po::store(po::command_line_parser(argc, argv).options(descr).run(), vm);
    po::notify(vm);
}
void User_Interface::operator()() {
    Input();
    std::string error;
    // if(er(file, LogWrite)==12){
    //     std::cout<<"Error open file"<<std::endl;
    //         exit (1);
    //     }
        Server Server;
        int s = Server.self_addr(error, LogWrite, port);
    while(true) {
        int work_sock = Server.client_addr(s, error, LogWrite);
        autorized(work_sock, file, LogWrite);    
        Calculator::math(work_sock);
        }
}
void User_Interface::Input() {
    if ( vm.count("help") or vm.empty() ) {
        descr.print(std::cout);
        exit(0);
    }
}