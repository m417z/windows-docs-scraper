typedef struct _SEC_WINNT_AUTH_IDENTITY_EXA {
  unsigned long Version;
  unsigned long Length;
  unsigned char *User;
  unsigned long UserLength;
  unsigned char *Domain;
  unsigned long DomainLength;
  unsigned char *Password;
  unsigned long PasswordLength;
  unsigned long Flags;
  unsigned char *PackageList;
  unsigned long PackageListLength;
} SEC_WINNT_AUTH_IDENTITY_EXA, *PSEC_WINNT_AUTH_IDENTITY_EXA;