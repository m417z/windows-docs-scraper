AUTHZAPI BOOL AuthzModifySids(
  [in]           AUTHZ_CLIENT_CONTEXT_HANDLE     hAuthzClientContext,
  [in]           AUTHZ_CONTEXT_INFORMATION_CLASS SidClass,
  [in]           PAUTHZ_SID_OPERATION            pSidOperations,
  [in, optional] PTOKEN_GROUPS                   pSids
);