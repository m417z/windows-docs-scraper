BOOL IMAGEAPI StackWalk2(
  [in]           DWORD                            MachineType,
  [in]           HANDLE                           hProcess,
  [in]           HANDLE                           hThread,
  [in, out]      LPSTACKFRAME_EX                  StackFrame,
  [in, out]      PVOID                            ContextRecord,
  [in, optional] PREAD_PROCESS_MEMORY_ROUTINE64   ReadMemoryRoutine,
  [in, optional] PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
  [in, optional] PGET_MODULE_BASE_ROUTINE64       GetModuleBaseRoutine,
  [in, optional] PTRANSLATE_ADDRESS_ROUTINE64     TranslateAddress,
  [in, optional] PGET_TARGET_ATTRIBUTE_VALUE64    GetTargetAttributeValue,
  [in]           DWORD                            Flags
);