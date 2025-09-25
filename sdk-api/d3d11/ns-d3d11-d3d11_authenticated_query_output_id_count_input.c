typedef struct D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT {
  D3D11_AUTHENTICATED_QUERY_INPUT Input;
  HANDLE                          DeviceHandle;
  HANDLE                          CryptoSessionHandle;
} D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT;