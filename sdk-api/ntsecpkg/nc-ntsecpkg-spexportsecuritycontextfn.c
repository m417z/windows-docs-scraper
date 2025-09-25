SpExportSecurityContextFn Spexportsecuritycontextfn;

NTSTATUS Spexportsecuritycontextfn(
  [in]  LSA_SEC_HANDLE phContext,
  [in]  ULONG fFlags,
  [out] PSecBuffer pPackedContext,
  [out] PHANDLE pToken
)
{...}