HRESULT GetSourceEntryStringWide(
  [in]            PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
  [in]            ULONG                      Which,
  [out]           PWSTR                      Buffer,
  [in]            ULONG                      BufferSize,
  [out, optional] PULONG                     StringSize
);