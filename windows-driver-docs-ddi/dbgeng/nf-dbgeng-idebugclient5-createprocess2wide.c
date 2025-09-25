HRESULT CreateProcess2Wide(
  [in]           ULONG64 Server,
  [in]           PWSTR   CommandLine,
  [in]           PVOID   OptionsBuffer,
  [in]           ULONG   OptionsBufferSize,
  [in, optional] PCWSTR  InitialDirectory,
  [in, optional] PCWSTR  Environment
);