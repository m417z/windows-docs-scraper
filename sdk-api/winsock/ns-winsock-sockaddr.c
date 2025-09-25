typedef struct sockaddr {
  u_short sa_family;
  char    sa_data[14];
} SOCKADDR, *PSOCKADDR, *LPSOCKADDR;