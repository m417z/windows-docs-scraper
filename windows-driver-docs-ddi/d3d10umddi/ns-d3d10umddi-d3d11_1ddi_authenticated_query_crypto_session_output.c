typedef struct D3D11_1DDI_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT {
  D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT Output;
  HANDLE                                DecodeHandle;
  HANDLE                                CryptoSessionHandle;
  HANDLE                                DeviceHandle;
} D3D11_1DDI_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT;