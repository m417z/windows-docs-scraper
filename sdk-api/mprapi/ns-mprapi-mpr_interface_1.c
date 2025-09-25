typedef struct _MPR_INTERFACE_1 {
  WCHAR                   wszInterfaceName[MAX_INTERFACE_NAME_LEN + 1];
  HANDLE                  hInterface;
  BOOL                    fEnabled;
  ROUTER_INTERFACE_TYPE   dwIfType;
  ROUTER_CONNECTION_STATE dwConnectionState;
  DWORD                   fUnReachabilityReasons;
  DWORD                   dwLastError;
  LPWSTR                  lpwsDialoutHoursRestriction;
} MPR_INTERFACE_1, *PMPR_INTERFACE_1;