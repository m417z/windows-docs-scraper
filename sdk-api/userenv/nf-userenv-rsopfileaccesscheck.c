USERENVAPI HRESULT RsopFileAccessCheck(
  [in]  LPWSTR     pszFileName,
  [in]  PRSOPTOKEN pRsopToken,
  [in]  DWORD      dwDesiredAccessMask,
  [out] LPDWORD    pdwGrantedAccessMask,
  [out] LPBOOL     pbAccessStatus
);