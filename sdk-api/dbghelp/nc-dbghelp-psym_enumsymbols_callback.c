PSYM_ENUMSYMBOLS_CALLBACK PsymEnumsymbolsCallback;

BOOL PsymEnumsymbolsCallback(
  [in]           PCSTR SymbolName,
  [in]           ULONG SymbolAddress,
  [in]           ULONG SymbolSize,
  [in, optional] PVOID UserContext
)
{...}