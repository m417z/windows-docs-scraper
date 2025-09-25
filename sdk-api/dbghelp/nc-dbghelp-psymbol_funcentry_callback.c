PSYMBOL_FUNCENTRY_CALLBACK PsymbolFuncentryCallback;

PVOID PsymbolFuncentryCallback(
  [in]           HANDLE hProcess,
  [in]           DWORD AddrBase,
  [in, optional] PVOID UserContext
)
{...}