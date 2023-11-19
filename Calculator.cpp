#include "Calculator.h"
void Calculator::math(int work_sock){
    uint32_t kolvo;
    uint32_t numb;
    uint32_t vect;
    recv(work_sock, &kolvo, sizeof(kolvo), 0);
    //цикл векторов
    for(uint32_t j=0; j<kolvo; j++){
        recv(work_sock, &numb, sizeof(numb), 0);//прием длинны для первого вектора
        uint32_t sum = 0;
//цикл значений
        for(uint32_t i=0; i<numb; i++){
            recv(work_sock, &vect, sizeof(vect), 0);
            if (sum > std::numeric_limits<uint32_t>::max() - vect)
                {
                sum = std::numeric_limits<uint32_t>::max();
                break;
                }
                sum = sum+vect;
            }
        uint32_t mfc;
        mfc = sum/kolvo;
        send(work_sock, &mfc, sizeof(mfc), 0);
        }
    std::cout << "Program finish!" <<std::endl;
    close(work_sock);
    }