#pragma once
#include <netinet/in.h>
#include <limits>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h> // HexEncoder
#include <boost/program_options.hpp> 
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
using namespace CryptoPP;
using namespace std;
#include <cryptopp/md5.h> // MD%, для другого алгоритма - другой заголовочный файл
std::string MD(std::string sah);
void errors(std::string error, std::string name);
int er(std::string file_name, std::string file_error);
void msgsend(int work_sock, string mess);
int autorized(int work_sock, string file_name, string file_error);




