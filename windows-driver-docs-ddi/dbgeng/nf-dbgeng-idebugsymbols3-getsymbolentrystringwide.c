HRESULT GetSymbolEntryStringWide(
  [in]            PDEBUG_MODULE_AND_ID Id,
  [in]            ULONG                Which,
  [out, optional] PWSTR                Buffer,
  [in]            ULONG                BufferSize,
  [out, optional] PULONG               StringSize
);