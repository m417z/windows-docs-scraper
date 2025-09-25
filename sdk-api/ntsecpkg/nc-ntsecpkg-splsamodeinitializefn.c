SpLsaModeInitializeFn Splsamodeinitializefn;

NTSTATUS Splsamodeinitializefn(
  [in]  ULONG LsaVersion,
  [out] PULONG PackageVersion,
  [out] PSECPKG_FUNCTION_TABLE *ppTables,
  [out] PULONG pcTables
)
{...}