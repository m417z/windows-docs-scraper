HRESULT GetTypeNameWide(
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [out, optional] PWSTR   NameBuffer,
  [in]            ULONG   NameBufferSize,
  [out, optional] PULONG  NameSize
);