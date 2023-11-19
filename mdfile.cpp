#include "mdfile.h"
void msgsend(int work_sock, string mess){
    char *buffer = new char[4096];
    std::strcpy(buffer, mess.c_str());
    send(work_sock, buffer, mess.length(), 0);
}

std::string MD(std::string sah){
Weak::MD5 hash;
    std::string digest;
    StringSource(sah, true,  new HashFilter(hash, new HexEncoder(new StringSink(digest))));  // строка-приемник
      return digest;
 }
int autorized(int work_sock, string file_name, string file_error){//аутентификация

                    std::string ok = "OK";
                    std::string salt = "2D2D2D2D2D2D2D22";
                    std::string err = "ERR";
                    std::string error;
                    char* msg = new char[256];
                    
                    //Авторизация
                    int size_m = recv(work_sock, msg, 256, 0);
                    std::string message(msg, size_m);
                    std::string login, hashq;
                    std::fstream file;
                    file.open(file_name);
                    getline (file, login, ':');
                    getline (file, hashq);
                    //std::cout << '"' << login << '"' << ' ' << '"' <<hashq << '"' << std::endl;
                    //std::cout << '"' << message << '"' << std::endl;

                        delete[] msg;
                    //СВЕРКА ЛОГИНОВ
                    if(message != login){
                        msgsend(work_sock,  err);
                        error = "Ошибка логина";
                        //errors(error, file_error);
                        close(work_sock);
                        return 1;
                    }else{

                    char* msg = new char[256];
                    //соль отправленная клиенту
                    msgsend(work_sock,  salt);
                    int size_m = recv(work_sock, msg, 256, 0);
                    std::string sah = salt + hashq;
                    std::string digest;
                    digest = MD(sah);
                    std::string new_msg(msg,size_m);
                    //СВЕРКА ПАРОЛЕЙ
                    if(digest != new_msg){
                        msgsend(work_sock,  err);
                        error = "Ошибка пароля";
                        //errors(error, file_error);
                        close(work_sock);
                        delete[] msg;
                        return 1;
                    }else{
                        delete[] msg;
                        msgsend(work_sock,  ok);
                    }
}
return 1;
}
    
    
    

