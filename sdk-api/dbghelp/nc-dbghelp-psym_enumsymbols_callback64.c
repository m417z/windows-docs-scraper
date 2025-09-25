PSYM_ENUMSYMBOLS_CALLBACK64 PsymEnumsymbolsCallback64;

BOOL PsymEnumsymbolsCallback64(
  [in]           PCSTR SymbolName,
  [in]           DWORD64 SymbolAddress,
  [in]           ULONG SymbolSize,
  [in, optional] PVOID UserContext
)
{...}