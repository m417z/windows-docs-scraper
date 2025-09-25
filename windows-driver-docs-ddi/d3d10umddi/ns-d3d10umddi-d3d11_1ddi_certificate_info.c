typedef struct D3D11_1DDI_CERTIFICATE_INFO {
  D3D11_1DDI_CERTIFICATE_TYPE CertificateType;
  union {
    D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE ChannelType;
    GUID                                  CryptoSessionType;
  };
} D3D11_1DDI_CERTIFICATE_INFO;