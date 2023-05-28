#ifndef TREM_H
#define TREM_H

#include <QThread>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);  //construtor
    void run();         //função a ser executada pela thread
    int getX();         //Retorna coordenada X
    int getY();         //Retorna coordenada Y
    void run_or_stop(bool b); //Para um trem ou o faz começar a andar, com 1 para andar e 0 para parar
    void setSpeed(int s); //Insere uma nova velocidade
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   bool can_go; //Se pode seguir ou não
};

#endif // TREM_H
