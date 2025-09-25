typedef struct drt_settings_tag {
  DWORD                  dwSize;
  ULONG                  cbKey;
  BYTE                   bProtocolMajorVersion;
  BYTE                   bProtocolMinorVersion;
  ULONG                  ulMaxRoutingAddresses;
  PWSTR                  pwzDrtInstancePrefix;
  HDRT_TRANSPORT         hTransport;
  DRT_SECURITY_PROVIDER  *pSecurityProvider;
  DRT_BOOTSTRAP_PROVIDER *pBootstrapProvider;
  DRT_SECURITY_MODE      eSecurityMode;
} DRT_SETTINGS, *PDRT_SETTINGS;