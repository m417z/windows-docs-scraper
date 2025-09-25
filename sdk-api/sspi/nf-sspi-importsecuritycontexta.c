SECURITY_STATUS SEC_ENTRY ImportSecurityContextA(
  [in]           LPSTR       pszPackage,
  [in]           PSecBuffer  pPackedContext,
  [in, optional] VOID        *Token,
  [out]          PCtxtHandle phContext
);