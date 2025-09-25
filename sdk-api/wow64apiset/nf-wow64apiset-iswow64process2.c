BOOL IsWow64Process2(
  [in]            HANDLE hProcess,
  [out]           USHORT *pProcessMachine,
  [out, optional] USHORT *pNativeMachine
);