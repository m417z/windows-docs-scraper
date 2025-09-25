typedef struct _CREDENTIAL_TARGET_INFORMATIONW {
#if ...
  wchar_t *TargetName;
#if ...
  wchar_t *NetbiosServerName;
#if ...
  wchar_t *DnsServerName;
#if ...
  wchar_t *NetbiosDomainName;
#if ...
  wchar_t *DnsDomainName;
#if ...
  wchar_t *DnsTreeName;
#if ...
  wchar_t *PackageName;
#else
  LPWSTR  TargetName;
#endif
#else
  LPWSTR  NetbiosServerName;
#endif
#else
  LPWSTR  DnsServerName;
#endif
#else
  LPWSTR  NetbiosDomainName;
#endif
#else
  LPWSTR  DnsDomainName;
#endif
#else
  LPWSTR  DnsTreeName;
#endif
#else
  LPWSTR  PackageName;
#endif
  ULONG   Flags;
  DWORD   CredTypeCount;
  LPDWORD CredTypes;
} CREDENTIAL_TARGET_INFORMATIONW, *PCREDENTIAL_TARGET_INFORMATIONW;