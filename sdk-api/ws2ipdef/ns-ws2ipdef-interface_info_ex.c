typedef struct _INTERFACE_INFO_EX {
  ULONG          iiFlags;
  SOCKET_ADDRESS iiAddress;
  SOCKET_ADDRESS iiBroadcastAddress;
  SOCKET_ADDRESS iiNetmask;
} INTERFACE_INFO_EX, *LPINTERFACE_INFO_EX;