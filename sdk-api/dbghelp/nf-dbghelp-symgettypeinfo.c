BOOL IMAGEAPI SymGetTypeInfo(
  [in]  HANDLE                    hProcess,
  [in]  DWORD64                   ModBase,
  [in]  ULONG                     TypeId,
  [in]  IMAGEHLP_SYMBOL_TYPE_INFO GetType,
  [out] PVOID                     pInfo
);