HRESULT CreateProcess2(
  [in]           ULONG64 Server,
  [in]           PSTR    CommandLine,
  [in]           PVOID   OptionsBuffer,
  [in]           ULONG   OptionsBufferSize,
  [in, optional] PCSTR   InitialDirectory,
  [in, optional] PCSTR   Environment
);