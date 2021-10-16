#include <iostream>
#include <QDebug>

int main()
{
    quint8 msgMatr[1][11] = {{0, }};

    QString inp_str("11100101101");

    for (int i = 0; i < 11; i++)
    {
        msgMatr[0][i] = (quint8)inp_str.mid(i, 1).toInt();
        printf("%d", msgMatr[0][i]);
    }
    printf("\n~~~~~~~~~~~~~~~\n");

    quint8 resMatr[1][15];

    quint8 result[15];

    quint8 checkMatr[11][15] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                                 { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                 { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                                 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
                                 { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                                 { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                 { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1},
                                 { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1},
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}};

    printf("\nResult (4 last is parity):\n");
    for(int j = 0; j < 15; j++)
    {
        resMatr[0][j]=0;
        for(int k = 0; k < 15; k++)
            resMatr[0][j] += msgMatr[0][k] * checkMatr[k][j];
    }

    for(int j = 0; j < 15; j++)
    {
        if(resMatr[0][j] % 2 != 0)
            resMatr[0][j] = 1;
        else
            resMatr[0][j] = 0;

        printf("%d", resMatr[0][j]);
    }
    printf("\n           ****");
    result[0] = resMatr[0][11];
    result[1] = resMatr[0][12];
    result[3] = resMatr[0][13];
    result[7] = resMatr[0][14];

    result[2] = resMatr[0][0];
    result[4] = resMatr[0][1];
    result[5] = resMatr[0][2];
    result[6] = resMatr[0][3];
    result[8] = resMatr[0][4];
    result[9] = resMatr[0][5];
    result[10] = resMatr[0][6];
    result[11] = resMatr[0][7];
    result[12] = resMatr[0][8];
    result[13] = resMatr[0][9];
    result[14] = resMatr[0][10];

    printf("\nResult:\n");
    for(int j = 0; j < 15; j++)
        printf("%d", result[j]);
    printf("\n** *   *");

}
