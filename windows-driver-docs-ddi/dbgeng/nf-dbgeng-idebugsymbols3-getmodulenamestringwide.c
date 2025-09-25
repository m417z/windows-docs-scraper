HRESULT GetModuleNameStringWide(
  [in]            ULONG   Which,
  [in]            ULONG   Index,
  [in]            ULONG64 Base,
  [out, optional] PWSTR   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  NameSize
);