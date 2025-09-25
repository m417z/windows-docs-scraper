typedef struct _INTERFACE_INFO {
  ULONG        iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO, *LPINTERFACE_INFO;