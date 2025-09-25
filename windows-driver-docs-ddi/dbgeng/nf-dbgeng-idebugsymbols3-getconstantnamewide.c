HRESULT GetConstantNameWide(
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [in]            ULONG64 Value,
  [out, optional] PWSTR   NameBuffer,
  [in]            ULONG   NameBufferSize,
  [out, optional] PULONG  NameSize
);