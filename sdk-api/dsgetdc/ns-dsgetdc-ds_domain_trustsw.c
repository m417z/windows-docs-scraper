typedef struct _DS_DOMAIN_TRUSTSW {
#if ...
  wchar_t *NetbiosDomainName;
#if ...
  wchar_t *DnsDomainName;
#else
  LPWSTR  NetbiosDomainName;
#endif
#else
  LPWSTR  DnsDomainName;
#endif
  ULONG   Flags;
  ULONG   ParentIndex;
  ULONG   TrustType;
  ULONG   TrustAttributes;
#if ...
  PISID   DomainSid;
#else
  PSID    DomainSid;
#endif
  GUID    DomainGuid;
} DS_DOMAIN_TRUSTSW, *PDS_DOMAIN_TRUSTSW;