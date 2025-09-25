PENUMLOADED_MODULES_CALLBACK PenumloadedModulesCallback;

BOOL PenumloadedModulesCallback(
  [in]           PCSTR ModuleName,
  [in]           ULONG ModuleBase,
  [in]           ULONG ModuleSize,
  [in, optional] PVOID UserContext
)
{...}