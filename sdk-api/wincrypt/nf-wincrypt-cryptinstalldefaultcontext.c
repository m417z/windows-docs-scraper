BOOL CryptInstallDefaultContext(
  [in]  HCRYPTPROV           hCryptProv,
  [in]  DWORD                dwDefaultType,
  [in]  const void           *pvDefaultPara,
  [in]  DWORD                dwFlags,
  [in]  void                 *pvReserved,
  [out] HCRYPTDEFAULTCONTEXT *phDefaultContext
);