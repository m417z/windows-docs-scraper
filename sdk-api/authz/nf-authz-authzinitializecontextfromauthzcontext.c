AUTHZAPI BOOL AuthzInitializeContextFromAuthzContext(
  [in]           DWORD                        Flags,
  [in]           AUTHZ_CLIENT_CONTEXT_HANDLE  hAuthzClientContext,
  [in, optional] PLARGE_INTEGER               pExpirationTime,
  [in]           LUID                         Identifier,
  [in]           PVOID                        DynamicGroupArgs,
  [out]          PAUTHZ_CLIENT_CONTEXT_HANDLE phNewAuthzClientContext
);