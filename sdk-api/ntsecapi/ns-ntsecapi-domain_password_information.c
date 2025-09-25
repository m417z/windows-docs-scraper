typedef struct _DOMAIN_PASSWORD_INFORMATION {
  USHORT            MinPasswordLength;
  USHORT            PasswordHistoryLength;
  ULONG             PasswordProperties;
#if ...
  OLD_LARGE_INTEGER MaxPasswordAge;
#if ...
  OLD_LARGE_INTEGER MinPasswordAge;
#else
  LARGE_INTEGER     MaxPasswordAge;
#endif
#else
  LARGE_INTEGER     MinPasswordAge;
#endif
} DOMAIN_PASSWORD_INFORMATION, *PDOMAIN_PASSWORD_INFORMATION;