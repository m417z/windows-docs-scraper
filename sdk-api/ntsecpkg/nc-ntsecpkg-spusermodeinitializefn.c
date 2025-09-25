SpUserModeInitializeFn Spusermodeinitializefn;

NTSTATUS Spusermodeinitializefn(
  [in]  ULONG LsaVersion,
  [out] PULONG PackageVersion,
  [out] PSECPKG_USER_FUNCTION_TABLE *ppTables,
  [out] PULONG pcTables
)
{...}