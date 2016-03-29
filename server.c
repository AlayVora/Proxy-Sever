/* A multi-user web proxy server in the internet domain using TCP
   The port number is passed as an argument */

#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

	static void *doit(void *);
	void str_echo(int);

	/* CONECT CLIENT METHOD  */

	int conectClient (int puerto, int direccion, struct sockaddr_in *socketAddr) 
	{
    int mySocket;
    char error[1000];
    
    if ( (mySocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        printf("Error when creating the socket\n");
        return -2;
    }
    
    socketAddr->sin_family = AF_INET;
    socketAddr->sin_addr.s_addr = direccion;
    socketAddr->sin_port = htons(puerto);
    
    if (connect (mySocket, (struct sockaddr *)socketAddr,sizeof (*socketAddr)) == -1) 
    {
        snprintf(error, sizeof(error), "Error in %s:%d\n", __FILE__, __LINE__);
        perror(error);
        printf("%s\n",error);
        printf ("-- Error when stablishing a connection\n");
        return -1;
    }
    return mySocket;
	}


	int hostname_to_ip(char * hostname , char* ip)
	{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
    
    if ( (he = gethostbyname( hostname ) ) == NULL)
    {
        // get the host info
        herror("gethostbyname");
        return 1;
    }
    
    addr_list = (struct in_addr **) he->h_addr_list;
    
    for(i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip , inet_ntoa(*addr_list[i]) );
        return 0;
    }
    
    return 1;
	}

	int main(int argc, char **argv) 
	{

	/* variables section */
	pthread_t tid;
	int                listenfd, connfd;
	pid_t              childpid;
	socklen_t          clilen;
	struct sockaddr_in cliaddr, servaddr;

	if (argc != 2) 
	{
        printf("\nUsage: tcp-server <Port Number>");
        exit(0);
    }

	/* creating a socket */
   	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
     	printf("\n%s: Error in socket", argv[0]);
	puts("Connection accepted");
     	exit(0);
}

	/* configuring server address structure */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port        = htons(atoi(argv[1])); 

	/* binding our socket to the service port */
	if (bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) 
	{
		printf("\n%s: Error in bind", argv[0]); 
		exit(0);
	} 

	/* convert our socket to a listening socket */
   	if (listen(listenfd, 5) < 0) 
	{
     	printf("\n%s: Error in listen", argv[0]); 
     	exit(0);
	} 

   	for ( ; ; ) 
	{
     	clilen = sizeof(cliaddr);

     /* accept a new connection and return a new socket descriptor to handle this new client */
     	if ((connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &clilen)) < 0) {
       	printf("\n%s: Error in accept", argv[0]); 
       	exit(0);
     	} 

    pthread_create(&tid, NULL, &doit, (void *) connfd);   
	}
	}

	static void * doit(void *arg) {
    pthread_detach(pthread_self());
    str_echo((int) arg);
    close((int) arg);
    return (NULL);
	}

	void str_echo (int sock_fd) {
	ssize_t n;
	char line[512];

	/* read from socket */
	n = read(sock_fd,line,512);
    //char *pch,*str1[100];
	//puts(line);

	char s[2] = ":";
	char *token,*str2[10];

   
	token = strtok(line, s);

      int i =0;
   
	while( token != NULL )
	{
    //printf( " %s\n", token );
    str2[i] =token;
  	//puts(token);

      token = strtok(NULL, s);
      i++;
	}




	/* Code for connecting with the webserver */ 

	struct sockaddr_in socketAddr;
	//char google[] ="www.google.com";
	char ip[16];
    int cache_size,     //size of the cache in KiB
			port,
			port_web = 80,
            dir,
            mySocket,
            socket_web;
	char buffer80[1000000];

	hostname_to_ip(str2[0],ip);





	dir = inet_addr (ip);
	//printf("%s",ip);
	//puts(ip);
    //printf("%s,%s,%s",str1[0],str1[1],str1[2]);

    /* Creation of a socket with Web*/
    
    socket_web = conectClient (port_web, dir, &socketAddr);
    //printf("socket_web: %d\n",socket_web);
    
    if (socket_web < 0) return -1;
    else printf("Socket created\n");
    
    char p[1000];
	
    snprintf(p, sizeof(p),
             "GET %sHTTP/1.1\r\nHost: %s:%d\r\nUser-Agent: TEST 0.1\r\n\r\n",str2[2],str2[0],atoi(str2[1]));
 	
	
    if (write(socket_web, p, strlen(p)+1) < 0 ) {
        close(socket_web);
        return 1;
    } else  
        //printf("GET frame sent\n");
	
    buffer80[0] = '\0';
    
    
    int bytes_recv = read(socket_web, buffer80, sizeof(buffer80));
    //printf("Read message from socket1\n");
    
    if (bytes_recv < 0) 
    {
        fprintf(stderr, "socket read error: %s\n", strerror(errno));
        close(socket_web);
        printf("Read message from socket2\n");
        exit(10);
    }
    
    close(socket_web);
    printf("Received message from web server\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	puts(buffer80);

	printf("Connection closed with web server\n");



	//printf("%s,%s,%s",str1[0],str1[1],str1[2]);

	if (n < 0) {
    printf("\nError in read"); 
    exit(0);
	} else if (n == 0) {
	return;
	} 

	/* back to the client */
	if (write(sock_fd, (const void*) buffer80, sizeof(buffer80)) < 0) {
    printf("\nError in write");
    exit(0);
	} 

  
	close(sock_fd);
	}
