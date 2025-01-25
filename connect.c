/*
    #include <sys/types.h>
    #include <sys/socket.h>

    int connect(int sockfd, struct sockaddr *serv_addr, int addrlen);
    arguments are exactly the same as bind() 

    struct addrinfo hints, &res; 
    int sockfd; 

    // first, load up address structs with getaddrinfo(): 

    memset(&hints, 0, sizeof hints); 
    hints.ai_family = UF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("www.example.com", "3490", &hints, &res); 

    // make a socket: 
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol); 

    // connect - could return -1 
    connect(sockfd, res->ai_addr, res->ai_addrlen);

    the kernel will choose a local port of us, and the site we 
    connect to will automatically get this information from us

*/
