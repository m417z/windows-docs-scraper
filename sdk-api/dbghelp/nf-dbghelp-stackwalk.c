BOOL IMAGEAPI StackWalk(
  [in]           DWORD                          MachineType,
  [in]           HANDLE                         hProcess,
  [in]           HANDLE                         hThread,
  [in, out]      LPSTACKFRAME                   StackFrame,
  [in, out]      PVOID                          ContextRecord,
  [in, optional] PREAD_PROCESS_MEMORY_ROUTINE   ReadMemoryRoutine,
  [in, optional] PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine,
  [in, optional] PGET_MODULE_BASE_ROUTINE       GetModuleBaseRoutine,
  [in, optional] PTRANSLATE_ADDRESS_ROUTINE     TranslateAddress
);