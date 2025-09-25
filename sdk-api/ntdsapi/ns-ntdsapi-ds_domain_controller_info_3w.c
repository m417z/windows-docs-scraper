typedef struct {
#if ...
  WCHAR  *NetbiosName;
#if ...
  WCHAR  *DnsHostName;
#if ...
  WCHAR  *SiteName;
#if ...
  WCHAR  *SiteObjectName;
#if ...
  WCHAR  *ComputerObjectName;
#if ...
  WCHAR  *ServerObjectName;
#if ...
  WCHAR  *NtdsDsaObjectName;
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
  LPWSTR SiteObjectName;
#endif
#else
  LPWSTR ComputerObjectName;
#endif
#else
  LPWSTR ServerObjectName;
#endif
#else
  LPWSTR NtdsDsaObjectName;
#endif
  BOOL   fIsPdc;
  BOOL   fDsEnabled;
  BOOL   fIsGc;
  BOOL   fIsRodc;
  GUID   SiteObjectGuid;
  GUID   ComputerObjectGuid;
  GUID   ServerObjectGuid;
  GUID   NtdsDsaObjectGuid;
} DS_DOMAIN_CONTROLLER_INFO_3W, *PDS_DOMAIN_CONTROLLER_INFO_3W;