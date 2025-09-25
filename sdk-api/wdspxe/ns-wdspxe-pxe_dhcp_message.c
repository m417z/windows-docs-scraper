typedef struct tagPXE_DHCP_MESSAGE {
  BYTE            Operation;
  BYTE            HardwareAddressType;
  BYTE            HardwareAddressLength;
  BYTE            HopCount;
  DWORD           TransactionID;
  WORD            SecondsSinceBoot;
  WORD            Reserved;
  ULONG           ClientIpAddress;
  ULONG           YourIpAddress;
  ULONG           BootstrapServerAddress;
  ULONG           RelayAgentIpAddress;
  BYTE            HardwareAddress[PXE_DHCP_HWAADR_SIZE];
  BYTE            HostName[PXE_DHCP_SERVER_SIZE];
  BYTE            BootFileName[PXE_DHCP_FILE_SIZE];
  union {
    BYTE  bMagicCookie[PXE_DHCP_MAGIC_COOKIE_SIZE];
    ULONG uMagicCookie;
  };
  PXE_DHCP_OPTION Option;
} PXE_DHCP_MESSAGE, *PPXE_DHCP_MESSAGE;