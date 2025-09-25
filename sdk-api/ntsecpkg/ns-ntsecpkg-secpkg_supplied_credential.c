typedef struct _SECPKG_SUPPLIED_CREDENTIAL {
  USHORT              cbHeaderLength;
  USHORT              cbStructureLength;
  SECPKG_SHORT_VECTOR UserName;
  SECPKG_SHORT_VECTOR DomainName;
  SECPKG_BYTE_VECTOR  PackedCredentials;
  ULONG               CredFlags;
} SECPKG_SUPPLIED_CREDENTIAL, *PSECPKG_SUPPLIED_CREDENTIAL;