SpImportSecurityContextFn Spimportsecuritycontextfn;

NTSTATUS Spimportsecuritycontextfn(
  [in]  PSecBuffer pPackedContext,
  [in]  HANDLE Token,
  [out] PLSA_SEC_HANDLE phContext
)
{...}