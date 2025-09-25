HRESULT GetConstantName(
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [in]            ULONG64 Value,
  [out, optional] PSTR    NameBuffer,
  [in]            ULONG   NameBufferSize,
  [out, optional] PULONG  NameSize
);