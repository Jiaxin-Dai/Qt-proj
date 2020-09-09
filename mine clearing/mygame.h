#ifndef MYGAME_H
#define MYGAME_H


class CMyGame
{
public:
    CMyGame();
    ~CMyGame();
    void Create();
    void Create(int,int,int);
    void Restart();
private:
    int flag(int m, int n);

public:
    int **Map;
    int Boom;//雷数
    int mx;  //行数
    int my;   //列数
    bool Onrbtdown(int m, int n);
    bool Onlrbtdown(int m, int n);
    bool Onlbtup(int m, int n);
    bool iswin();
    int winf;
    int rBoom;
    bool first;
    int timer;
};


#endif // MYGAME_H
