BOOL IMAGEAPI SymEnumLinesW(
  [in]           HANDLE                   hProcess,
  [in]           ULONG64                  Base,
  [in, optional] PCWSTR                   Obj,
  [in, optional] PCWSTR                   File,
  [in]           PSYM_ENUMLINES_CALLBACKW EnumLinesCallback,
  [in, optional] PVOID                    UserContext
);