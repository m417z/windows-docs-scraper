PSYMBOL_FUNCENTRY_CALLBACK64 PsymbolFuncentryCallback64;

PVOID PsymbolFuncentryCallback64(
  [in]           HANDLE hProcess,
  [in]           ULONG64 AddrBase,
  [in, optional] ULONG64 UserContext
)
{...}