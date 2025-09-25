PSYMBOL_REGISTERED_CALLBACK64 PsymbolRegisteredCallback64;

BOOL PsymbolRegisteredCallback64(
  [in]           HANDLE hProcess,
  [in]           ULONG ActionCode,
  [in, optional] ULONG64 CallbackData,
  [in, optional] ULONG64 UserContext
)
{...}