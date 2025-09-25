PENUMLOADED_MODULES_CALLBACK64 PenumloadedModulesCallback64;

BOOL PenumloadedModulesCallback64(
  [in]           PCSTR ModuleName,
  [in]           DWORD64 ModuleBase,
  [in]           ULONG ModuleSize,
  [in, optional] PVOID UserContext
)
{...}