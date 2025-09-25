typedef struct {
#if ...
  CHAR  *NetbiosName;
#if ...
  CHAR  *DnsHostName;
#if ...
  CHAR  *SiteName;
#if ...
  CHAR  *SiteObjectName;
#if ...
  CHAR  *ComputerObjectName;
#if ...
  CHAR  *ServerObjectName;
#if ...
  CHAR  *NtdsDsaObjectName;
#else
  LPSTR NetbiosName;
#endif
#else
  LPSTR DnsHostName;
#endif
#else
  LPSTR SiteName;
#endif
#else
  LPSTR SiteObjectName;
#endif
#else
  LPSTR ComputerObjectName;
#endif
#else
  LPSTR ServerObjectName;
#endif
#else
  LPSTR NtdsDsaObjectName;
#endif
  BOOL  fIsPdc;
  BOOL  fDsEnabled;
  BOOL  fIsGc;
  BOOL  fIsRodc;
  GUID  SiteObjectGuid;
  GUID  ComputerObjectGuid;
  GUID  ServerObjectGuid;
  GUID  NtdsDsaObjectGuid;
} DS_DOMAIN_CONTROLLER_INFO_3A, *PDS_DOMAIN_CONTROLLER_INFO_3A;