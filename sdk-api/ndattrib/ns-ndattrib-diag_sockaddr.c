typedef struct tagSOCK_ADDR {
  USHORT family;
  CHAR   data[126];
} DIAG_SOCKADDR, *PDIAG_SOCK_ADDR;