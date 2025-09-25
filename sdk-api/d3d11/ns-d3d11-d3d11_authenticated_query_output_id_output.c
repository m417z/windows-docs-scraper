typedef struct D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT {
  D3D11_AUTHENTICATED_QUERY_OUTPUT Output;
  HANDLE                           DeviceHandle;
  HANDLE                           CryptoSessionHandle;
  UINT                             OutputIDIndex;
  UINT64                           OutputID;
} D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT;