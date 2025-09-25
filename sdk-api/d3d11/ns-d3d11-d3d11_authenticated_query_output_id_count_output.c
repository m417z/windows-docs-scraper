typedef struct D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT {
  D3D11_AUTHENTICATED_QUERY_OUTPUT Output;
  HANDLE                           DeviceHandle;
  HANDLE                           CryptoSessionHandle;
  UINT                             OutputIDCount;
} D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT;