typedef struct tagSOLE_AUTHENTICATION_SERVICE {
  DWORD   dwAuthnSvc;
  DWORD   dwAuthzSvc;
  OLECHAR *pPrincipalName;
  HRESULT hr;
} SOLE_AUTHENTICATION_SERVICE;