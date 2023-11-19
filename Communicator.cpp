#include "Communicator.h"
int Server::self_addr(string error, string file_error, int port){
            int s = socket(AF_INET, SOCK_STREAM, 0);//создается сокет для сервера
            sockaddr_in * self_addr = new (sockaddr_in); 
            self_addr->sin_family = AF_INET;
            self_addr->sin_port = htons(port);
            // self_addr->sin_addr.s_addr = inet_addr("127.0.0.1");
            self_addr->sin_addr.s_addr = htonl(INADDR_ANY);
            std::cout << "Wait for connect client...\n";
        int b = bind(s,(const sockaddr*) self_addr,sizeof(sockaddr_in));//закрепляет сокет
            if(b == -1) {
                std::cout << "Binding error\n";
                error = "error binding";
                //errors(error, file_error);
                return 1;
            }
            listen(s, SOMAXCONN);//ловит запросы к сокету
            return s;
            }

int Server::client_addr(int s, string error, string file_error){
                sockaddr_in * client_addr = new sockaddr_in;
                socklen_t len = sizeof (sockaddr_in);
                int work_sock = accept(s, (sockaddr*)(client_addr), &len);//создание сокета для клиента
                if(work_sock == -1) {
                    std::cout << "Error #2\n";
                    error = "error #2";
                    //errors(error, file_error);
                    return 1;
                }
                else {
                    //Успешное подключение к серверу
                    std::cout << "Successfull client connection!\n";
                    return work_sock;
                }
                }