PSYMBOL_REGISTERED_CALLBACK PsymbolRegisteredCallback;

BOOL PsymbolRegisteredCallback(
  [in]           HANDLE hProcess,
  [in]           ULONG ActionCode,
  [in, optional] PVOID CallbackData,
  [in, optional] PVOID UserContext
)
{...}