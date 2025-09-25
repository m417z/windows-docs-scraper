PSYM_ENUMERATESYMBOLS_CALLBACK PsymEnumeratesymbolsCallback;

BOOL PsymEnumeratesymbolsCallback(
  [in]           PSYMBOL_INFO pSymInfo,
  [in]           ULONG SymbolSize,
  [in, optional] PVOID UserContext
)
{...}