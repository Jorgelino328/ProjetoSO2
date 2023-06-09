#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <QSemaphore>
#include <iostream>

QSemaphore sem0(1);
QSemaphore sem1(1);
QSemaphore sem2(1);
QSemaphore sem3(1);
QSemaphore sem4(1);
QSemaphore sem5(1);
QSemaphore sem6(1);


QMutex mutex0;
QMutex mutex1;
QMutex mutex2;
QMutex mutex3;
QMutex mutex4;
QMutex mutex5;
QMutex mutex6;


Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::run(){
    while(true){
        switch(ID){
        case 1: // Trem 1
            // Região de risco 0
            if(x <= 460){
                if(x == 440 && y == 40){
                    //std::cout << "t1 locked it" << std::endl;
                    mutex0.lock();
                    sem0.acquire(1);
                }
                if(x == 420 && y == 240){
                     //std::cout << "t1 unlocked it" << std::endl;
                    sem0.release(1);
                    mutex0.unlock();
                }
            }
            // Região de risco 1
            if(y <= 240){
                if(y == 220 && x == 360){
                    //std::cout << "t1 locked it" << std::endl;
                    mutex1.lock();
                    sem1.acquire(1);
                }
                if(y == 240 && x == 260){
                    //std::cout << "t1 unlocked it" << std::endl;
                    sem1.release(1);
                    mutex1.unlock();
                }
            }


            // Região de risco 2
            if(y >= 220){
                if(y == 220 && x == 440){
                    std::cout << "t1 locked it" << std::endl;
                    mutex2.lock();
                    sem2.acquire(1);
                }
                if(y == 240  && x == 260){
                    std::cout << "t1 unlocked it" << std::endl;
                    sem2.release(1);
                    mutex2.unlock();
                }
            }

            if (x < 440 && y == 40)
                x += 10;
            else if (x == 440 && y < 240)
                y += 10;
            else if (x > 240 && y == 240)
                x -= 10;
            else
                y -= 10;

            emit updateGUI(ID, x, y);
            break;
        case 2: // Trem 2
            // Região de risco 0
            if(x >= 440){
                if(x == 460 && y == 240){
                    //std::cout << "t2 locked it" << std::endl;
                    mutex0.lock();
                    sem0.acquire(1);
                }
                if(x == 440 && y == 40){
                    //std::cout << "t2 unlocked it" << std::endl;
                    sem0.release(1);
                    mutex0.unlock();
                }
            }


            // Região de risco 3
            if(y == 240){
                if(x == 650){
                    std::cout << "t2 locked it" << std::endl;
                    mutex3.lock();
                    sem3.acquire(1);
                }
                if(x == 560){
                    std::cout << "t2 unlocked it" << std::endl;
                    sem3.release(1);
                    mutex3.unlock();
                }
            }



            // Região de risco 4
            if(y <= 260){
                if(y == 250 &&  x == 640){
                    mutex4.lock();
                    sem4.acquire(1);
                }
                if(y == 240 && x == 540){
                    sem4.release(1);
                    mutex4.unlock();
                }
            }

            if (x < 640 && y == 40)
                x += 10;
            else if (x == 640 && y < 240)
                y += 10;
            else if (x > 440 && y == 240)
                x -= 10;
            else
                y -= 10;

            emit updateGUI(ID, x, y);
            break;
        case 3: // Trem 3

            // Região de risco 1
            if(y == 240){
                if(x == 220){
                    mutex1.lock();
                    sem1.acquire(1);
                }
                if(x == 340){
                    sem1.release(1);
                    mutex1.unlock();
                }
            }

            // Região de risco 5
            if(x == 220 && y == 240){
                mutex5.lock();
                sem5.acquire(1);
            }
            if(y == 440){
                sem5.release(1);
                mutex5.unlock();
            }


            if (x < 340 && y == 240)
                x += 10;
            else if (x == 340 && y < 440)
                y += 10;
            else if (x > 140 && y == 440)
                x -= 10;
            else
                y -= 10;

            emit updateGUI(ID, x, y);

            break;
        case 4: // Trem 4

            // Região de risco 2
            if(y >= 240){
                if(y == 260 && x == 340){
                    std::cout << "t4 locked it" << std::endl;
                    mutex2.lock();
                    sem2.acquire(1);
                }
                if(y == 240 && x == 460){
                    std::cout << "t4 unlocked it" << std::endl;
                    sem2.release(1);
                    mutex2.unlock();
                }
            }


            // Região de risco 3
            if(y == 240){
                if(x == 440){
                    std::cout << "t4 unlocked it" << std::endl;
                    mutex3.lock();
                    sem3.acquire(1);
                }
                if(x == 560){
                    std::cout << "t4 unlocked it" << std::endl;
                    sem3.release(1);
                    mutex3.unlock();
                }
            }


            // Região de risco 5
            if(x >= 340){
                if(x == 360 && y == 440){
                    mutex5.lock();
                    sem5.acquire(1);
                }
                if(x == 340 && y == 240){
                    sem5.release(1);
                    mutex5.unlock();
                }
            }


            // Região de risco 6
            if(x <= 540){
                if(x == 520 && y == 240){
                    mutex6.lock();
                    sem6.acquire(1);
                }
                if(x == 540 && y == 440){
                    sem6.release(1);
                    mutex6.unlock();
                }
            }

            if (x < 540 && y == 240)
                x += 10;
            else if (x == 540 && y < 440)
                y += 10;
            else if (x > 340 && y == 440)
                x -= 10;
            else
                y -= 10;

            emit updateGUI(ID, x, y);
            break;

        case 5: // Trem 5


            // Região de risco 4
            if(y == 260){
                if(x == 540){
                    mutex4.lock();
                    sem4.acquire(1);
                }
                if(x == 740){
                    sem4.release(1);
                    mutex4.unlock();
                }
            }

            // Região de risco 6
            if(x >= 540){
                if(x == 560 && y == 440){
                    mutex6.lock();
                    sem6.acquire(1);
                }
                if(x == 540 && y == 240){
                    sem6.release(1);
                    mutex6.unlock();
                }
            }

            if (x < 740 && y == 240)
                x += 10;
            else if (x == 740 && y < 440)
                y += 10;
            else if (x > 540 && y == 440)
                x -= 10;
            else
                y -= 10;

            emit updateGUI(ID, x, y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setSpeed(int s){
    this->velocidade = s;
}
