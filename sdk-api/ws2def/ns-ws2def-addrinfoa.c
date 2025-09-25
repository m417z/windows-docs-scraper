typedef struct addrinfo {
  int             ai_flags;
  int             ai_family;
  int             ai_socktype;
  int             ai_protocol;
  size_t          ai_addrlen;
  char            *ai_canonname;
  struct sockaddr *ai_addr;
  struct addrinfo *ai_next;
} ADDRINFOA, *PADDRINFOA;