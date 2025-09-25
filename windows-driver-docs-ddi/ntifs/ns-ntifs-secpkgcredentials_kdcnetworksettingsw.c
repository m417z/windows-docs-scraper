typedef struct _SecPkgCredentials_KdcNetworkSettingsW {
  ULONG  Version;
  ULONG  Flags;
  USHORT ProxyServerOffset;
  USHORT ProxyServerLength;
  USHORT ClientTlsCredOffset;
  USHORT ClientTlsCredLength;
  ULONG  DcDiscoveryFlags;
} SecPkgCredentials_KdcNetworkSettingsW, *PSecPkgCredentials_KdcNetworkSettingsW;