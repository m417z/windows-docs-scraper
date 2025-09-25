PVOID IMAGEAPI SymFunctionTableAccess64AccessRoutines(
  [in]           HANDLE                         hProcess,
  [in]           DWORD64                        AddrBase,
  [in, optional] PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
  [in, optional] PGET_MODULE_BASE_ROUTINE64     GetModuleBaseRoutine
);