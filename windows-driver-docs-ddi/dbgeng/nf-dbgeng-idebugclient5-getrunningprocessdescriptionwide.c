HRESULT GetRunningProcessDescriptionWide(
  [in]            ULONG64 Server,
  [in]            ULONG   SystemId,
  [in]            ULONG   Flags,
  [out, optional] PWSTR   ExeName,
  [in]            ULONG   ExeNameSize,
  [out, optional] PULONG  ActualExeNameSize,
  [out, optional] PWSTR   Description,
  [in]            ULONG   DescriptionSize,
  [out, optional] PULONG  ActualDescriptionSize
);