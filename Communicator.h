#include "mdfile.h"
#pragma once
class Server{
public:
int self_addr(string error, string file_error, int port);
int client_addr(int s, string error, string file_error);
};