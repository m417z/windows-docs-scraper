typedef struct _COAUTHINFO {
  DWORD          dwAuthnSvc;
  DWORD          dwAuthzSvc;
  LPWSTR         pwszServerPrincName;
  DWORD          dwAuthnLevel;
  DWORD          dwImpersonationLevel;
  COAUTHIDENTITY *pAuthIdentityData;
  DWORD          dwCapabilities;
} COAUTHINFO;