/*
    #include <sys/types.h>
    #include <sys/socket.h>

    int socket(int domain, int type, int protocol);

    The arguments say what kind of socket you want 
        - domain: either IPv4 (PF_INET) or IPv6 (PF_INET6)
        - type: stream (SOCK_STREAM) or datagram (SOCK_DGRAM)
        - protocol: TCP or UDP (either 0 to select automatically 
                    or via getprotoname()) 
    Example usage - 

    int s; 
    struct addrinfo hints, *res; 

    // do the lookup 
    // [pretend we already filled out the "hints" struct]
    getaddrinfo("www.example.com", "http", &hints, &res);
    
    s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
                    
    socket() simply returns to you a socket descriptor that you can 
    use in later system calls, or -1 on error
*/


