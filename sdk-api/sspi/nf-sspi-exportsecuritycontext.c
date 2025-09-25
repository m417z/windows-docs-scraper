KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY ExportSecurityContext(
  [in]            PCtxtHandle phContext,
  [in]            ULONG       fFlags,
  [out]           PSecBuffer  pPackedContext,
  [out, optional] void        **pToken
);