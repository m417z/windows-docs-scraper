typedef struct _DHCPDS_SERVERS {
  DWORD           Flags;
  DWORD           NumElements;
  LPDHCPDS_SERVER Servers;
} DHCPDS_SERVERS, *LPDHCPDS_SERVERS, *PDHCPDS_SERVERS;