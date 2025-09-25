HRESULT GetFieldNameWide(
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [in]            ULONG   FieldIndex,
  [out, optional] PWSTR   NameBuffer,
  [in]            ULONG   NameBufferSize,
  [out, optional] PULONG  NameSize
);