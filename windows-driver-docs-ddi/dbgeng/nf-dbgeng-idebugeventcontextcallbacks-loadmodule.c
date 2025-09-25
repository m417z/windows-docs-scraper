HRESULT LoadModule(
       ULONG64 ImageFileHandle,
       ULONG64 BaseOffset,
       ULONG   ModuleSize,
       PCWSTR  ModuleName,
       PCWSTR  ImageName,
       ULONG   CheckSum,
       ULONG   TimeDateStamp,
  [in] PVOID   Context,
  [in] ULONG   ContextSize
);