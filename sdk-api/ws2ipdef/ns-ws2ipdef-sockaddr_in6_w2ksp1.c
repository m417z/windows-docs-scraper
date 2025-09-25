typedef struct sockaddr_in6_w2ksp1 {
  short           sin6_family;
  USHORT          sin6_port;
  ULONG           sin6_flowinfo;
  struct in6_addr sin6_addr;
  ULONG           sin6_scope_id;
} SOCKADDR_IN6_W2KSP1, *PSOCKADDR_IN6_W2KSP1, *LPSOCKADDR_IN6_W2KSP1;