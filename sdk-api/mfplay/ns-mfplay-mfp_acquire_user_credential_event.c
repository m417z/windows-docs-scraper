typedef struct MFP_ACQUIRE_USER_CREDENTIAL_EVENT {
  MFP_EVENT_HEADER     header;
  DWORD_PTR            dwUserData;
  BOOL                 fProceedWithAuthentication;
  HRESULT              hrAuthenticationStatus;
  LPCWSTR              pwszURL;
  LPCWSTR              pwszSite;
  LPCWSTR              pwszRealm;
  LPCWSTR              pwszPackage;
  LONG                 nRetries;
  MFP_CREDENTIAL_FLAGS flags;
  IMFNetCredential     *pCredential;
} MFP_ACQUIRE_USER_CREDENTIAL_EVENT;