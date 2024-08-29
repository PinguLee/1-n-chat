#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

#define PORT 3288
#define BUFFER_SIZE 1024

#pragma comment(lib, "ws2_32.lib") 

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[BUFFER_SIZE] = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("소켓 초기화 실패\n");
        exit(1);
    }
    printf("소켓 초기화 성공\n");

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        printf("소켓 생성 실패: %d\n", WSAGetLastError());
        WSACleanup();
        exit(1);
    }
    printf("소켓 생성 성공\n");

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(PORT);

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        printf("서버 연결 실패: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        exit(1);
    }

    printf("서버 연결 성공\n");

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
