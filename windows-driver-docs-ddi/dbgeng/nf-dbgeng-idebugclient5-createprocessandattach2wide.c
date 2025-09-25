HRESULT CreateProcessAndAttach2Wide(
  [in]           ULONG64 Server,
  [in, optional] PWSTR   CommandLine,
  [in]           PVOID   OptionsBuffer,
  [in]           ULONG   OptionsBufferSize,
  [in, optional] PCWSTR  InitialDirectory,
  [in, optional] PCWSTR  Environment,
  [in]           ULONG   ProcessId,
  [in]           ULONG   AttachFlags
);