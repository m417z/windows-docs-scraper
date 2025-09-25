PSYM_ENUMSYMBOLS_CALLBACK64W PsymEnumsymbolsCallback64w;

BOOL PsymEnumsymbolsCallback64w(
  [in]           PCWSTR SymbolName,
  [in]           DWORD64 SymbolAddress,
  [in]           ULONG SymbolSize,
  [in, optional] PVOID UserContext
)
{...}