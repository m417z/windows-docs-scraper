typedef struct _DDICERTIFICATEINFO {
  [in] D3DDDI_CERTIFICATETYPE      CertificateType;
  [in] DDIAUTHENTICATEDCHANNELTYPE ChannelType;
  [in] GUID                        CryptoSessionType;
} DDICERTIFICATEINFO;