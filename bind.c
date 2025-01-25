/*
    Once you have a socket you might have to associate that socket 
    with a port on your local machine. The port number is used by 
    the kernel to match an incomming packet to a certain process's
    socket descriptor. This is typically done if you're going to 
    act as a "server" and thus going to call listen(). It isn't 
    required if you're going to only act as a client and call 
    thus call connect()

    #include <sys/types.h>
    #include <sys/socket.h>

    int bind(int sockfd, struct sockaddr *my_addr, int addrlen);

    sockfd is the socket file descriptor returned by socket()
    my_addr is a pointer to a struct sockaddr that contains 
    information about your address, namely, port and IP address
    addrlen is the length in bytes of that address 

    Example usage - 

    struct addrinfo hints, *res; 
    int sockfd; 

    // first, load up addres struct with getaddrinfo(): 
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;    // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = AI_PASSIVE;    // fill in my IP for me 

    getaddrinfo(NULL, "3490", &hints, &res); 

    // make a socket: 

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // bind it to the port we passed in to getaddrinfo(): 

    bind(sockfd, res->ai_addr, res->ai_addrlen); 
*/

