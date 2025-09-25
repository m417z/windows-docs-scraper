HRESULT CreateProcessAndAttach2(
  [in]           ULONG64 Server,
  [in, optional] PSTR    CommandLine,
  [in]           PVOID   OptionsBuffer,
  [in]           ULONG   OptionsBufferSize,
  [in, optional] PCSTR   InitialDirectory,
  [in, optional] PCSTR   Environment,
  [in]           ULONG   ProcessId,
  [in]           ULONG   AttachFlags
);