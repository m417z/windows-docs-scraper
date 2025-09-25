PSYM_ENUMPROCESSES_CALLBACK PsymEnumprocessesCallback;

BOOL PsymEnumprocessesCallback(
  [in] HANDLE hProcess,
  [in] PVOID UserContext
)
{...}