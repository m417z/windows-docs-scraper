AUTHZAPI BOOL AuthzGetInformationFromContext(
  [in]  AUTHZ_CLIENT_CONTEXT_HANDLE     hAuthzClientContext,
  [in]  AUTHZ_CONTEXT_INFORMATION_CLASS InfoClass,
  [in]  DWORD                           BufferSize,
  [out] PDWORD                          pSizeRequired,
  [out] PVOID                           Buffer
);