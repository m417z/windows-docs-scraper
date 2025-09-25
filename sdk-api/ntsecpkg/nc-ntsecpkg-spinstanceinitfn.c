SpInstanceInitFn Spinstanceinitfn;

NTSTATUS Spinstanceinitfn(
  [in]  ULONG Version,
  [in]  PSECPKG_DLL_FUNCTIONS FunctionTable,
  [out] PVOID *UserFunctions
)
{...}