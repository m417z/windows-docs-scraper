SECURITY_STATUS SEC_ENTRY ChangeAccountPasswordW(
  [in]      SEC_WCHAR      *pszPackageName,
  [in]      SEC_WCHAR      *pszDomainName,
  [in]      SEC_WCHAR      *pszAccountName,
  [in]      SEC_WCHAR      *pszOldPassword,
  [in]      SEC_WCHAR      *pszNewPassword,
  [in]      BOOLEAN        bImpersonating,
  [in]      unsigned long  dwReserved,
  [in, out] PSecBufferDesc pOutput
);