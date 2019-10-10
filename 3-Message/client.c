#include <stdio.h>      /* printf(),fprintf()に必要 */
#include <stdlib.h>     /* perror(),atoi()に必要 */
#include <sys/socket.h> /* socket(),bind(),accept()に必要 */
#include <arpa/inet.h>  /* sockaddr_in,inet_addr()に必要 */
#include <string.h>     /* strlen()に必要 */
#include <unistd.h>     /* close()に必要 */

#define BUF_SIZE 256 /* マジックナンバーで256の定義 */
#define MONEY_DIGIT_SIZE 10

void DieWithError(char *) int prepare_client_socket(char *, int);
int