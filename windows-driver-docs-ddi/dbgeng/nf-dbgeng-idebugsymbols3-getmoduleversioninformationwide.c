HRESULT GetModuleVersionInformationWide(
  [in]            ULONG   Index,
  [in]            ULONG64 Base,
  [in]            PCWSTR  Item,
  [out, optional] PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  VerInfoSize
);