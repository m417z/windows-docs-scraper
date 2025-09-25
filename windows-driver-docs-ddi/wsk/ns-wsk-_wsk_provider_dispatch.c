typedef struct _WSK_PROVIDER_DISPATCH {
  USHORT                    Version;
  USHORT                    Reserved;
  PFN_WSK_SOCKET            WskSocket;
  PFN_WSK_SOCKET_CONNECT    WskSocketConnect;
  PFN_WSK_CONTROL_CLIENT    WskControlClient;
  PFN_WSK_GET_ADDRESS_INFO  WskGetAddressInfo;
  PFN_WSK_FREE_ADDRESS_INFO WskFreeAddressInfo;
  PFN_WSK_GET_NAME_INFO     WskGetNameInfo;
} WSK_PROVIDER_DISPATCH, *PWSK_PROVIDER_DISPATCH;