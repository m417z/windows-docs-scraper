AUTHZAPI BOOL AuthzInitializeContextFromToken(
  [in]           DWORD                         Flags,
  [in]           HANDLE                        TokenHandle,
  [in]           AUTHZ_RESOURCE_MANAGER_HANDLE hAuthzResourceManager,
  [in, optional] PLARGE_INTEGER                pExpirationTime,
  [in]           LUID                          Identifier,
  [in, optional] PVOID                         DynamicGroupArgs,
  [out]          PAUTHZ_CLIENT_CONTEXT_HANDLE  phAuthzClientContext
);