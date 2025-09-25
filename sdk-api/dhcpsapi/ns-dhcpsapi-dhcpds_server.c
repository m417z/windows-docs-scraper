typedef struct _DHCPDS_SERVER {
  DWORD  Version;
  LPWSTR ServerName;
  DWORD  ServerAddress;
  DWORD  Flags;
  DWORD  State;
  LPWSTR DsLocation;
  DWORD  DsLocType;
} DHCPDS_SERVER, *LPDHCPDS_SERVER, *PDHCPDS_SERVER;