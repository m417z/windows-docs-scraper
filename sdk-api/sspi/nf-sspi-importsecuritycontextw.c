KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY ImportSecurityContextW(
  [in]           PSECURITY_STRING pszPackage,
  [in]           PSecBuffer       pPackedContext,
  [in, optional] void             *Token,
  [out]          PCtxtHandle      phContext
);