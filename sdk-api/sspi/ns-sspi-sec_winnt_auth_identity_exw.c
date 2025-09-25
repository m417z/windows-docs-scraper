typedef struct _SEC_WINNT_AUTH_IDENTITY_EXW {
  unsigned long  Version;
  unsigned long  Length;
  unsigned short *User;
  unsigned long  UserLength;
  unsigned short *Domain;
  unsigned long  DomainLength;
  unsigned short *Password;
  unsigned long  PasswordLength;
  unsigned long  Flags;
  unsigned short *PackageList;
  unsigned long  PackageListLength;
} SEC_WINNT_AUTH_IDENTITY_EXW, *PSEC_WINNT_AUTH_IDENTITY_EXW;