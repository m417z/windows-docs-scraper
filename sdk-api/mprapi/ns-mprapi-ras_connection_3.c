typedef struct _RAS_CONNECTION_3 {
  DWORD                 dwVersion;
  DWORD                 dwSize;
  HANDLE                hConnection;
  WCHAR                 wszUserName[UNLEN + 1];
  ROUTER_INTERFACE_TYPE dwInterfaceType;
  GUID                  guid;
  PPP_INFO_3            PppInfo3;
  RAS_QUARANTINE_STATE  rasQuarState;
  FILETIME              timer;
} RAS_CONNECTION_3, *PRAS_CONNECTION_3;