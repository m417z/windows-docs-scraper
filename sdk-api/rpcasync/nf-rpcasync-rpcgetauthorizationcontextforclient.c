RPC_STATUS RpcGetAuthorizationContextForClient(
  [in, optional] RPC_BINDING_HANDLE ClientBinding,
  [in]           BOOL               ImpersonateOnReturn,
  [in]           PVOID              Reserved1,
  [in, optional] PLARGE_INTEGER     pExpirationTime,
  [in]           LUID               Reserved2,
  [in]           DWORD              Reserved3,
  [in]           PVOID              Reserved4,
  [out]          PVOID              *pAuthzClientContext
);