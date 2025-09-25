typedef struct _RAS_CONNECTION_0 {
  HANDLE                hConnection;
  HANDLE                hInterface;
  DWORD                 dwConnectDuration;
  ROUTER_INTERFACE_TYPE dwInterfaceType;
  DWORD                 dwConnectionFlags;
  WCHAR                 wszInterfaceName[MAX_INTERFACE_NAME_LEN + 1];
  WCHAR                 wszUserName[UNLEN + 1];
  WCHAR                 wszLogonDomain[DNLEN + 1];
  WCHAR                 wszRemoteComputer[NETBIOS_NAME_LEN + 1];
} RAS_CONNECTION_0, *PRAS_CONNECTION_0;