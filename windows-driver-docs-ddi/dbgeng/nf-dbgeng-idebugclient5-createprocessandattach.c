HRESULT CreateProcessAndAttach(
  [in]           ULONG64 Server,
  [in, optional] PSTR    CommandLine,
  [in]           ULONG   CreateFlags,
  [in]           ULONG   ProcessId,
  [in]           ULONG   AttachFlags
);