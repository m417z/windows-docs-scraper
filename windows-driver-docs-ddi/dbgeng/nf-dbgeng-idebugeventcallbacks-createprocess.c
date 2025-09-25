HRESULT CreateProcess(
  [in]           ULONG64 ImageFileHandle,
  [in]           ULONG64 Handle,
  [in]           ULONG64 BaseOffset,
  [in]           ULONG   ModuleSize,
  [in, optional] PCSTR   ModuleName,
  [in, optional] PCSTR   ImageName,
  [in]           ULONG   CheckSum,
  [in]           ULONG   TimeDateStamp,
  [in]           ULONG64 InitialThreadHandle,
  [in]           ULONG64 ThreadDataOffset,
  [in]           ULONG64 StartOffset
);