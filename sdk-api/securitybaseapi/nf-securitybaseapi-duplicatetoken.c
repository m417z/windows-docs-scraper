BOOL DuplicateToken(
  [in]  HANDLE                       ExistingTokenHandle,
  [in]  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
  [out] PHANDLE                      DuplicateTokenHandle
);