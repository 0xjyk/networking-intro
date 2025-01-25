/*
    We use listen when we want to wait for incomming connections 
    and we want to handle them in some way. We typically call 
    listen() followed by accept()

    int listen(int sockfd, int backlog); 
    sockfd is the usual socked file descriptor returned from socket() 
    backlog is the number of connections allowed on the incoming queue
    The incoming connections are the connection requests that haven't 
    been accepted yet. Thus backlog is the number of such requests allowed
    to persist at any given point of time.

    One would typically listen using the following procedure

    getaddrinfo(); 
    socket(); 
    bind(); 
    listen();
    // accept comes here
*/


