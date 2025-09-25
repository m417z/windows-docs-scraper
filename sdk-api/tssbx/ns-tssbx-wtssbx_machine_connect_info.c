typedef struct __MIDL_IWTSSBPlugin_0006 {
  WCHAR             wczMachineFQDN[257];
  WCHAR             wczMachineNetBiosName[17];
  DWORD             dwNumOfIPAddr;
  WTSSBX_IP_ADDRESS IPaddr[12];
} WTSSBX_MACHINE_CONNECT_INFO;