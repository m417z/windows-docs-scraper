typedef struct _RAS_CONNECTION_2 {
  HANDLE                hConnection;
  WCHAR                 wszUserName[UNLEN + 1];
  ROUTER_INTERFACE_TYPE dwInterfaceType;
  GUID                  guid;
  PPP_INFO_2            PppInfo2;
} RAS_CONNECTION_2, *PRAS_CONNECTION_2;