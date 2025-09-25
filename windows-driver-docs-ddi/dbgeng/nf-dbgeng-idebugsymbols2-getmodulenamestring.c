HRESULT GetModuleNameString(
  [in]            ULONG   Which,
  [in]            ULONG   Index,
  [in]            ULONG64 Base,
  [out, optional] PSTR    Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  NameSize
);