HRESULT CreateProcess(
       ULONG64 ImageFileHandle,
       ULONG64 Handle,
       ULONG64 BaseOffset,
       ULONG   ModuleSize,
       PCWSTR  ModuleName,
       PCWSTR  ImageName,
       ULONG   CheckSum,
       ULONG   TimeDateStamp,
       ULONG64 InitialThreadHandle,
       ULONG64 ThreadDataOffset,
       ULONG64 StartOffset,
  [in] PVOID   Context,
  [in] ULONG   ContextSize
);