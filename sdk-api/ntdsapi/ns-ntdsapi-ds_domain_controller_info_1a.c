typedef struct {
#if ...
  CHAR  *NetbiosName;
#if ...
  CHAR  *DnsHostName;
#if ...
  CHAR  *SiteName;
#if ...
  CHAR  *ComputerObjectName;
#if ...
  CHAR  *ServerObjectName;
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
  LPSTR ComputerObjectName;
#endif
#else
  LPSTR ServerObjectName;
#endif
  BOOL  fIsPdc;
  BOOL  fDsEnabled;
} DS_DOMAIN_CONTROLLER_INFO_1A, *PDS_DOMAIN_CONTROLLER_INFO_1A;