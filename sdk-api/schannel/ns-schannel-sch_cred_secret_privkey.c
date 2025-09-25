typedef struct _SCH_CRED_SECRET_PRIVKEY {
  DWORD dwType;
  PBYTE pPrivateKey;
  DWORD cbPrivateKey;
  PSTR  pszPassword;
} SCH_CRED_SECRET_PRIVKEY, *PSCH_CRED_SECRET_PRIVKEY;