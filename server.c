// a stream socket server 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "3490" // the port users will be connecting to

#define BACKLOG 10  // how many pending connections queue will hold


void sigchild_handler(int s) {
    // waitpid() might overwrite errno, so we save and restore it: 
    int saved_errno = errno; 

    while (waitpid(-1, NULL, WNOHANG) > 0); 

    errno = saved_errno;
}

// get sockaddr, IPv4 or IPv6: 
void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INEXT) {
        return &(((struct sockaddr_in *)sa)->sin_addr); 
    }

    return &(((struct sockaddr_in *)sa)->sin6_addr); 
}

int main(void) {
    int sockfd, new_fd; 
    struct addrinfo hints, *servinfo, *p; 
    struct sockaddr_storage their_addr; // connector's address info
    socklen_t sin_size; 
    struct sigaction sa; 
    int yes = 1; 
    char s[INET6_ADDRSTRLEN]; 
    int rv; 

    memset(&hints, 0, sizeof hints); 
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = AI_PASSIVE;    // use my IP 

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv)); 
        return 1; 
    }

    // loop through all the results and bind to the first we can 
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, 
                        p->ai_protocol)) == -1) {
            perror("server: socket"); 
            continue; 
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, 
                    sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1); 
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd); 
            perror("server: bind"); 
            continue; 
        }
        break;
    }

    freeaddrinfo(servinfo); // all done with this structure 

    if (p == NULL) {
        fprintf(stderr, "server: failed to bind\n"); 
        exit(1); 
    }

    if (listen(sockdf, BACKLOG) == -1) {
        perror("listen"); 
        exit(1); 
    }








