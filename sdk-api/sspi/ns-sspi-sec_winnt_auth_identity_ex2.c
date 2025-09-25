typedef struct _SEC_WINNT_AUTH_IDENTITY_EX2 {
  unsigned long  Version;
  unsigned short cbHeaderLength;
  unsigned long  cbStructureLength;
  unsigned long  UserOffset;
  unsigned short UserLength;
  unsigned long  DomainOffset;
  unsigned short DomainLength;
  unsigned long  PackedCredentialsOffset;
  unsigned short PackedCredentialsLength;
  unsigned long  Flags;
  unsigned long  PackageListOffset;
  unsigned short PackageListLength;
} SEC_WINNT_AUTH_IDENTITY_EX2, *PSEC_WINNT_AUTH_IDENTITY_EX2;