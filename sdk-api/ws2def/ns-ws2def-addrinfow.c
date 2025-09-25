typedef struct addrinfoW {
  int              ai_flags;
  int              ai_family;
  int              ai_socktype;
  int              ai_protocol;
  size_t           ai_addrlen;
  PWSTR            ai_canonname;
  struct sockaddr  *ai_addr;
  struct addrinfoW *ai_next;
} ADDRINFOW, *PADDRINFOW;