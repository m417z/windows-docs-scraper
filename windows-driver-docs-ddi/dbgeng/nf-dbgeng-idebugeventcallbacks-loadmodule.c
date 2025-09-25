HRESULT LoadModule(
  [in]           ULONG64 ImageFileHandle,
  [in]           ULONG64 BaseOffset,
  [in]           ULONG   ModuleSize,
  [in, optional] PCSTR   ModuleName,
  [in, optional] PCSTR   ImageName,
  [in]           ULONG   CheckSum,
  [in]           ULONG   TimeDateStamp
);