typedef struct _DSROLE_PRIMARY_DOMAIN_INFO_BASIC {
  DSROLE_MACHINE_ROLE MachineRole;
  ULONG               Flags;
  LPWSTR              DomainNameFlat;
  LPWSTR              DomainNameDns;
  LPWSTR              DomainForestName;
  GUID                DomainGuid;
} DSROLE_PRIMARY_DOMAIN_INFO_BASIC, *PDSROLE_PRIMARY_DOMAIN_INFO_BASIC;