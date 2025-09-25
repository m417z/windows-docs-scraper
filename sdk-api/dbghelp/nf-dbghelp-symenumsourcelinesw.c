BOOL IMAGEAPI SymEnumSourceLinesW(
  [in]           HANDLE                   hProcess,
  [in]           ULONG64                  Base,
  [in, optional] PCWSTR                   Obj,
  [in, optional] PCWSTR                   File,
  [in, optional] DWORD                    Line,
  [in]           DWORD                    Flags,
  [in]           PSYM_ENUMLINES_CALLBACKW EnumLinesCallback,
  [in, optional] PVOID                    UserContext
);