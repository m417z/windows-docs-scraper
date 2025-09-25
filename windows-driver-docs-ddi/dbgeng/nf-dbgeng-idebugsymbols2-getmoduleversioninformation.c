HRESULT GetModuleVersionInformation(
  [in]            ULONG   Index,
  [in]            ULONG64 Base,
  [in]            PCSTR   Item,
  [out, optional] PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  VerInfoSize
);