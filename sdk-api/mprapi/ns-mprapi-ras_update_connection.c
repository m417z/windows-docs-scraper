typedef struct RAS_UPDATE_CONNECTION_ {
  MPRAPI_OBJECT_HEADER Header;
  DWORD                dwIfIndex;
  WCHAR                wszLocalEndpointAddress[MAXIPADRESSLEN + 1];
  WCHAR                wszRemoteEndpointAddress[MAXIPADRESSLEN + 1];
} RAS_UPDATE_CONNECTION, *PRAS_UPDATE_CONNECTION;