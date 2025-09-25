AUTHZAPI BOOL AuthzAddSidsToContext(
  [in]  AUTHZ_CLIENT_CONTEXT_HANDLE  hAuthzClientContext,
  [in]  PSID_AND_ATTRIBUTES          Sids,
  [in]  DWORD                        SidCount,
  [in]  PSID_AND_ATTRIBUTES          RestrictedSids,
  [in]  DWORD                        RestrictedSidCount,
  [out] PAUTHZ_CLIENT_CONTEXT_HANDLE phNewAuthzClientContext
);