HRESULT GetTypeName(
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [out, optional] PSTR    NameBuffer,
  [in]            ULONG   NameBufferSize,
  [out, optional] PULONG  NameSize
);