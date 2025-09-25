HRESULT GetFieldName(
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [in]            ULONG   FieldIndex,
  [out, optional] PSTR    NameBuffer,
  [in]            ULONG   NameBufferSize,
  [out, optional] PULONG  NameSize
);