PENUMLOADED_MODULES_CALLBACKW64 PenumloadedModulesCallbackw64;

BOOL PenumloadedModulesCallbackw64(
  [in]           PCWSTR ModuleName,
  [in]           DWORD64 ModuleBase,
  [in]           ULONG ModuleSize,
  [in, optional] PVOID UserContext
)
{...}