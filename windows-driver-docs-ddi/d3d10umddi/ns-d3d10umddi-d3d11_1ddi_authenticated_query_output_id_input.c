typedef struct D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT {
  D3D11_1DDI_AUTHENTICATED_QUERY_INPUT Input;
  HANDLE                               DeviceHandle;
  HANDLE                               CryptoSessionHandle;
  UINT                                 OutputIDIndex;
} D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT;