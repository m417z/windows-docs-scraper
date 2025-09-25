BOOL IMAGEAPI SymEnumSourceLines(
  [in]           HANDLE                  hProcess,
  [in]           ULONG64                 Base,
  [in, optional] PCSTR                   Obj,
  [in, optional] PCSTR                   File,
  [in, optional] DWORD                   Line,
  [in]           DWORD                   Flags,
  [in]           PSYM_ENUMLINES_CALLBACK EnumLinesCallback,
  [in, optional] PVOID                   UserContext
);