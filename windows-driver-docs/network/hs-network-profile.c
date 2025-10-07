typedef struct _HS_NETWORK_PROFILE {
  DWORD  dwNetworkCapabilities;
  USHORT usPriority;
  DWORD  dwSupportedSIMCount;
  DWORD  dmNumCellularExceptions;
  DWORD  dwNetworkStringID;
  DWORD  dwKeepAliveTimeMins;
  WCHAR  szRealm[HS_CONST_MAX_REALM_LENGTH+1];
} HS_NETWORK_PROFILE, *PHS_NETWORK_PROFILE;