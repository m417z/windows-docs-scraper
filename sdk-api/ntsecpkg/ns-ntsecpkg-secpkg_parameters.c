typedef struct _SECPKG_PARAMETERS {
  ULONG          Version;
  ULONG          MachineState;
  ULONG          SetupMode;
  PSID           DomainSid;
  UNICODE_STRING DomainName;
  UNICODE_STRING DnsDomainName;
  GUID           DomainGuid;
} SECPKG_PARAMETERS, *PSECPKG_PARAMETERS, SECPKG_EVENT_DOMAIN_CHANGE, *PSECPKG_EVENT_DOMAIN_CHANGE;