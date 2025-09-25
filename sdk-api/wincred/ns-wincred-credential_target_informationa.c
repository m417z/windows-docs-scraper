typedef struct _CREDENTIAL_TARGET_INFORMATIONA {
  LPSTR   TargetName;
  LPSTR   NetbiosServerName;
  LPSTR   DnsServerName;
  LPSTR   NetbiosDomainName;
  LPSTR   DnsDomainName;
  LPSTR   DnsTreeName;
  LPSTR   PackageName;
  ULONG   Flags;
  DWORD   CredTypeCount;
  LPDWORD CredTypes;
} CREDENTIAL_TARGET_INFORMATIONA, *PCREDENTIAL_TARGET_INFORMATIONA;