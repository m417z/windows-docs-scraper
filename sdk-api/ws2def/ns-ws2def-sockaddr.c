typedef struct sockaddr {
#if ...
  u_short        sa_family;
#else
  ADDRESS_FAMILY sa_family;
#endif
  CHAR           sa_data[14];
} SOCKADDR, *PSOCKADDR, *LPSOCKADDR;