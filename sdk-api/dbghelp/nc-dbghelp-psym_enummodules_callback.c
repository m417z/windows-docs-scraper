PSYM_ENUMMODULES_CALLBACK PsymEnummodulesCallback;

BOOL PsymEnummodulesCallback(
  [in]           PCSTR ModuleName,
  [in]           ULONG BaseOfDll,
  [in, optional] PVOID UserContext
)
{...}