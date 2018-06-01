#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")
int main(){
	int rv;
	printf("Set & Initial Socket Tool.\n");
    	WSADATA wsaData;
    	WSAStartup(MAKEWORD(2, 2), &wsaData);
    
  	printf("Create Socket.\n");
    	SOCKET serverSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   
  	printf("Bind local IP and Port.\n");
    	sockaddr_in sockAddr;
    	memset(&sockAddr, 0, sizeof(sockAddr));
    	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
    	sockAddr.sin_port = htons(1234); 
    	rv = bind(serverSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    
	  printf("Listen.\n");
   	 rv = listen(serverSock, 20);
    
	  printf("Accept Clinet.\n");
    	SOCKADDR clientAddr;
    	int nSize = sizeof(SOCKADDR);
    	SOCKET clientSock = accept(serverSock, (SOCKADDR*)&clientAddr, &nSize);
    
	  printf("Communication.\n");

    	char *str = "Hello World!";
	  int strLen = strlen(str) + 1;
    	rv = send(clientSock, str, strLen, NULL);
    
    	closesocket(clientSock);
    	closesocket(serverSock);
    
    	WSACleanup();

	return 0;
}
