typedef struct D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION {
  D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT Parameters;
  HANDLE                                   DecodeHandle;
  HANDLE                                   CryptoSessionHandle;
  HANDLE                                   DeviceHandle;
} D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION;