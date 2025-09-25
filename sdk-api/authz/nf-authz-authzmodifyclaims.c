AUTHZAPI BOOL AuthzModifyClaims(
  [in]           AUTHZ_CLIENT_CONTEXT_HANDLE            hAuthzClientContext,
  [in]           AUTHZ_CONTEXT_INFORMATION_CLASS        ClaimClass,
  [in]           PAUTHZ_SECURITY_ATTRIBUTE_OPERATION    pClaimOperations,
  [in, optional] PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION pClaims
);