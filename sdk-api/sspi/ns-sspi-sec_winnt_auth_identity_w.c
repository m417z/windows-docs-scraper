typedef struct _SEC_WINNT_AUTH_IDENTITY_W {
  unsigned short *User;
  unsigned long  UserLength;
  unsigned short *Domain;
  unsigned long  DomainLength;
  unsigned short *Password;
  unsigned long  PasswordLength;
  unsigned long  Flags;
} SEC_WINNT_AUTH_IDENTITY_W, *PSEC_WINNT_AUTH_IDENTITY_W;