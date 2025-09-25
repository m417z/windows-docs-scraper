HRESULT GetModuleNames(
  [in]            ULONG   Index,
  [in]            ULONG64 Base,
  [out, optional] PSTR    ImageNameBuffer,
  [in]            ULONG   ImageNameBufferSize,
  [out, optional] PULONG  ImageNameSize,
  [out, optional] PSTR    ModuleNameBuffer,
  [in]            ULONG   ModuleNameBufferSize,
  [out, optional] PULONG  ModuleNameSize,
  [out, optional] PSTR    LoadedImageNameBuffer,
  [in]            ULONG   LoadedImageNameBufferSize,
  [out, optional] PULONG  LoadedImageNameSize
);