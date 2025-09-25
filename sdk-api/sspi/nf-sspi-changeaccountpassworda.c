SECURITY_STATUS SEC_ENTRY ChangeAccountPasswordA(
  [in]      SEC_CHAR       *pszPackageName,
  [in]      SEC_CHAR       *pszDomainName,
  [in]      SEC_CHAR       *pszAccountName,
  [in]      SEC_CHAR       *pszOldPassword,
  [in]      SEC_CHAR       *pszNewPassword,
  [in]      BOOLEAN        bImpersonating,
  [in]      unsigned long  dwReserved,
  [in, out] PSecBufferDesc pOutput
);