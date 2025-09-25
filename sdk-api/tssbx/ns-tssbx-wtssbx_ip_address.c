typedef struct __MIDL_IWTSSBPlugin_0004 {
  WTSSBX_ADDRESS_FAMILY AddressFamily;
  BYTE                  Address[16];
  unsigned short        PortNumber;
  DWORD                 dwScope;
} WTSSBX_IP_ADDRESS;