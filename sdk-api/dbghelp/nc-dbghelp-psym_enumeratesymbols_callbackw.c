PSYM_ENUMERATESYMBOLS_CALLBACKW PsymEnumeratesymbolsCallbackw;

BOOL PsymEnumeratesymbolsCallbackw(
  [in]           PSYMBOL_INFOW pSymInfo,
  [in]           ULONG SymbolSize,
  [in, optional] PVOID UserContext
)
{...}