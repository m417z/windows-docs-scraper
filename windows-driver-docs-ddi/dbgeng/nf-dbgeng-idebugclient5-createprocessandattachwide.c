HRESULT CreateProcessAndAttachWide(
  [in]           ULONG64 Server,
  [in, optional] PWSTR   CommandLine,
  [in]           ULONG   CreateFlags,
  [in]           ULONG   ProcessId,
  [in]           ULONG   AttachFlags
);