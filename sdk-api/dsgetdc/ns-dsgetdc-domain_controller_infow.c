typedef struct _DOMAIN_CONTROLLER_INFOW {
#if ...
  wchar_t *DomainControllerName;
#else
  LPWSTR  DomainControllerName;
#endif
#if ...
  wchar_t *DomainControllerAddress;
#else
  LPWSTR  DomainControllerAddress;
#endif
  ULONG   DomainControllerAddressType;
  GUID    DomainGuid;
#if ...
  wchar_t *DomainName;
#else
  LPWSTR  DomainName;
#endif
#if ...
  wchar_t *DnsForestName;
#else
  LPWSTR  DnsForestName;
#endif
  ULONG   Flags;
#if ...
  wchar_t *DcSiteName;
#else
  LPWSTR  DcSiteName;
#endif
#if ...
  wchar_t *ClientSiteName;
#else
  LPWSTR  ClientSiteName;
#endif
} DOMAIN_CONTROLLER_INFOW, *PDOMAIN_CONTROLLER_INFOW;