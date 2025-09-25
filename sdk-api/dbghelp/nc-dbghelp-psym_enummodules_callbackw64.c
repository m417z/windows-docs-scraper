PSYM_ENUMMODULES_CALLBACKW64 PsymEnummodulesCallbackw64;

BOOL PsymEnummodulesCallbackw64(
  [in]           PCWSTR ModuleName,
  [in]           DWORD64 BaseOfDll,
  [in, optional] PVOID UserContext
)
{...}