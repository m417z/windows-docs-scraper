typedef struct _MPR_INTERFACE_0 {
  WCHAR                   wszInterfaceName[MAX_INTERFACE_NAME_LEN + 1];
  HANDLE                  hInterface;
  BOOL                    fEnabled;
  ROUTER_INTERFACE_TYPE   dwIfType;
  ROUTER_CONNECTION_STATE dwConnectionState;
  DWORD                   fUnReachabilityReasons;
  DWORD                   dwLastError;
} MPR_INTERFACE_0, *PMPR_INTERFACE_0;