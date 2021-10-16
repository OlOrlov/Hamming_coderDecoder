#include <iostream>
#include <QDebug>

int main()
{
    quint8 msgMatr[1][15] = {{0, }};
    quint8 input[15];

    QString inp_str("001100110101010");

    for (int i = 0; i < 15; i++)
    {
        input[i] = (quint8)inp_str.mid(i, 1).toInt();
        printf("%d", input[i]);
    }
    printf("\n** *   *\n");
    printf("~~~~~~~~~~~~~~~\n");

//ДЛЯ ИМИТАЦИИ ОШИБКИ
//    int k = 1;
//    k--;
//    if(input[k])
//        input[k] = 0;
//    else
//        input[k] = 1;

    msgMatr[0][0]  = input[2];
    msgMatr[0][1]  = input[4];
    msgMatr[0][2]  = input[5];
    msgMatr[0][3]  = input[6];
    msgMatr[0][4]  = input[8];
    msgMatr[0][5]  = input[9];
    msgMatr[0][6]  = input[10];
    msgMatr[0][7]  = input[11];
    msgMatr[0][8]  = input[12];
    msgMatr[0][9]  = input[13];
    msgMatr[0][10] = input[14];
    msgMatr[0][11] = input[0];
    msgMatr[0][12] = input[1];
    msgMatr[0][13] = input[3];
    msgMatr[0][14] = input[7];

    for (int i = 0; i < 15; i++)
        printf("%d", msgMatr[0][i]);

    printf("\n           ****");
    printf("\n~~~~~~~~~~~~~~~\n");

    quint8 resMatr[1][4];
    quint8 checkMatr[15][4] = { {1, 1, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {1, 1, 1, 0},
                                {1, 0, 0, 1},
                                {0, 1, 0, 1},
                                {1, 1, 0, 1},
                                {0, 0, 1, 1},
                                {1, 0, 1, 1},
                                {0, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1},
                              };

    for(int j = 0; j < 4; j++)
    {
        resMatr[0][j]=0;
        for(int k = 0; k < 15; k++)
            resMatr[0][j] += msgMatr[0][k] * checkMatr[k][j];
    }

    //for printing result
    for(int j = 0; j < 4; j++)
    {
        if(resMatr[0][j] % 2 != 0)
            resMatr[0][j] = 1;
        else
            resMatr[0][j] = 0;

        //printf("%d", resMatr[0][j]);
    }

    int mark = (resMatr[0][3]<<3) + (resMatr[0][2]<<2) + (resMatr[0][1]<<1) + resMatr[0][0];
    if(mark)
        qDebug()<<"\nError in:"<<mark;
    else
        qDebug()<<"Correct";
}
