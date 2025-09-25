typedef struct _DOMAIN_CONTROLLER_INFOA {
  LPSTR DomainControllerName;
  LPSTR DomainControllerAddress;
  ULONG DomainControllerAddressType;
  GUID  DomainGuid;
  LPSTR DomainName;
  LPSTR DnsForestName;
  ULONG Flags;
  LPSTR DcSiteName;
  LPSTR ClientSiteName;
} DOMAIN_CONTROLLER_INFOA, *PDOMAIN_CONTROLLER_INFOA;