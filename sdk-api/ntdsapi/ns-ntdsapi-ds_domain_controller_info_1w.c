typedef struct {
#if ...
  WCHAR  *NetbiosName;
#if ...
  WCHAR  *DnsHostName;
#if ...
  WCHAR  *SiteName;
#if ...
  WCHAR  *ComputerObjectName;
#if ...
  WCHAR  *ServerObjectName;
#else
  LPWSTR NetbiosName;
#endif
#else
  LPWSTR DnsHostName;
#endif
#else
  LPWSTR SiteName;
#endif
#else
  LPWSTR ComputerObjectName;
#endif
#else
  LPWSTR ServerObjectName;
#endif
  BOOL   fIsPdc;
  BOOL   fDsEnabled;
} DS_DOMAIN_CONTROLLER_INFO_1W, *PDS_DOMAIN_CONTROLLER_INFO_1W;