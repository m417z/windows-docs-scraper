SpGetContextTokenFn Spgetcontexttokenfn;

NTSTATUS Spgetcontexttokenfn(
  [in]  LSA_SEC_HANDLE ContextHandle,
  [out] PHANDLE ImpersonationToken
)
{...}