BOOL DuplicateTokenEx(
  [in]           HANDLE                       hExistingToken,
  [in]           DWORD                        dwDesiredAccess,
  [in, optional] LPSECURITY_ATTRIBUTES        lpTokenAttributes,
  [in]           SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
  [in]           TOKEN_TYPE                   TokenType,
  [out]          PHANDLE                      phNewToken
);