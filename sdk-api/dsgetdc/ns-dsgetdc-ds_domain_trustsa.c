typedef struct _DS_DOMAIN_TRUSTSA {
  LPSTR NetbiosDomainName;
  LPSTR DnsDomainName;
  ULONG Flags;
  ULONG ParentIndex;
  ULONG TrustType;
  ULONG TrustAttributes;
  PSID  DomainSid;
  GUID  DomainGuid;
} DS_DOMAIN_TRUSTSA, *PDS_DOMAIN_TRUSTSA;