AUTHZAPI BOOL AuthzInitializeContextFromSid(
  [in]           DWORD                         Flags,
  [in]           PSID                          UserSid,
  [in, optional] AUTHZ_RESOURCE_MANAGER_HANDLE hAuthzResourceManager,
  [in]           PLARGE_INTEGER                pExpirationTime,
  [in]           LUID                          Identifier,
  [in, optional] PVOID                         DynamicGroupArgs,
  [out]          PAUTHZ_CLIENT_CONTEXT_HANDLE  phAuthzClientContext
);