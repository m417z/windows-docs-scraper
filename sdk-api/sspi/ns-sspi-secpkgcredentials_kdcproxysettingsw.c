typedef struct _SecPkgCredentials_KdcProxySettingsW {
  ULONG  Version;
  ULONG  Flags;
  USHORT ProxyServerOffset;
  USHORT ProxyServerLength;
  USHORT ClientTlsCredOffset;
  USHORT ClientTlsCredLength;
} SecPkgCredentials_KdcProxySettingsW, *PSecPkgCredentials_KdcProxySettingsW;