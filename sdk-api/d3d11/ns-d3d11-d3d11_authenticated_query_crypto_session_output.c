typedef struct D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT {
  D3D11_AUTHENTICATED_QUERY_OUTPUT Output;
  HANDLE                           DecoderHandle;
  HANDLE                           CryptoSessionHandle;
  HANDLE                           DeviceHandle;
} D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT;