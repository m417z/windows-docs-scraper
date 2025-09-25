typedef struct _MFNetCredentialManagerGetParam {
  HRESULT hrOp;
  BOOL    fAllowLoggedOnUser;
  BOOL    fClearTextPackage;
  LPCWSTR pszUrl;
  LPCWSTR pszSite;
  LPCWSTR pszRealm;
  LPCWSTR pszPackage;
  LONG    nRetries;
} MFNetCredentialManagerGetParam;