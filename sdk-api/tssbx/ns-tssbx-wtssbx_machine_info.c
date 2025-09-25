typedef struct __MIDL_IWTSSBPlugin_0007 {
  WTSSBX_MACHINE_CONNECT_INFO ClientConnectInfo;
  WCHAR                       wczFarmName[257];
  WTSSBX_IP_ADDRESS           InternalIPAddress;
  DWORD                       dwMaxSessionsLimit;
  DWORD                       ServerWeight;
  WTSSBX_MACHINE_SESSION_MODE SingleSessionMode;
  WTSSBX_MACHINE_DRAIN        InDrain;
  WTSSBX_MACHINE_STATE        MachineState;
} WTSSBX_MACHINE_INFO;