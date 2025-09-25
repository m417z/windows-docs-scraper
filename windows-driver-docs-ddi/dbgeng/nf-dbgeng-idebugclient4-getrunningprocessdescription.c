HRESULT GetRunningProcessDescription(
  [in]            ULONG64 Server,
  [in]            ULONG   SystemId,
  [in]            ULONG   Flags,
  [out, optional] PSTR    ExeName,
  [in]            ULONG   ExeNameSize,
  [out, optional] PULONG  ActualExeNameSize,
  [out, optional] PSTR    Description,
  [in]            ULONG   DescriptionSize,
  [out, optional] PULONG  ActualDescriptionSize
);