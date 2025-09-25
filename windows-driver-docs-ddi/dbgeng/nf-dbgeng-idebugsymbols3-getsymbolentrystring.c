HRESULT GetSymbolEntryString(
  [in]            PDEBUG_MODULE_AND_ID Id,
  [in]            ULONG                Which,
  [out, optional] PSTR                 Buffer,
  [in]            ULONG                BufferSize,
  [out, optional] PULONG               StringSize
);