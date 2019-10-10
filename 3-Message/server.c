#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256
#define MONEY_DIGIT_SIZE 10

void DieWithError(char *);
int prepare_srever_socket(int);
void commun(int);

int main(int argc, char **argv[])
{
    struct sockaddr_in clientAddress;
    unsigned int szClientAddr;
    int cliSock;
    int servSock = prepare_srever_socket(10001); /* 待ち受け用ソケットの作成(PF_INET=IPv4,SOCKET_STREAM=TCP,0=残りはお任せ) */
    listen(servSock, 5);
    while (1)
    {
        szClientAddr = sizeof(clientAddress);                                         /* 受信データの形式のメモリサイズを取得 */
        cliSock = accept(servSock, (struct sockaddr *)&clientAddress, &szClientAddr); /*  */
        commun(cliSock);                                                              /* ユーザー定義 */
    }
    close(servSock); /* serverをクローズする */
    return 0;
}
void DirWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

int prepare_server_socket(int port)
{
    int serverSock = socket(PF_INET, SOCK_STREAM, 0);
    if (servSock < 0)
        DieWithError("socket() failed");

    struct socaddr_in serverAddress;
    unsigned int szClientAddr;
    int cliSock;

    int servSock = prepare_server_socket(10001); /* 待ち受け用ソケットの作成(PF_INET=IPv4,SOCKET_STREAM=TCP,0=残りはお任せ) */

    listen(servSock); /* 順番待ち(第二引数が順番待ちしても良いクライアント数) */
    while (1)
    {
        szClientAddr = sizeof(clientAddress);                                         /* 受信データの形式のメモリサイズを取得 */
        cliSock = accept(servSock, (struct sockaddr *)&clientAddress, &szClientAddr); /*  */
        commun(cliSock);                                                              /* ユーザー定義 */
    }
    close(servSock); /* serverをクローズする */
    return 0;
}