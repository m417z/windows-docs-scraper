typedef struct D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT {
  D3D11_AUTHENTICATED_CONFIGURE_INPUT Parameters;
  HANDLE                              DecoderHandle;
  HANDLE                              CryptoSessionHandle;
  HANDLE                              DeviceHandle;
} D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT;