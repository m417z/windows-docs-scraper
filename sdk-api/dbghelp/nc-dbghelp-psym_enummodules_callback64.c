PSYM_ENUMMODULES_CALLBACK64 PsymEnummodulesCallback64;

BOOL PsymEnummodulesCallback64(
  [in]           PCSTR ModuleName,
  [in]           DWORD64 BaseOfDll,
  [in, optional] PVOID UserContext
)
{...}