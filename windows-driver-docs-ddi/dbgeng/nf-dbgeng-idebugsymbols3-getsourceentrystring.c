HRESULT GetSourceEntryString(
  [in]            PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
  [in]            ULONG                      Which,
  [out]           PSTR                       Buffer,
  [in]            ULONG                      BufferSize,
  [out, optional] PULONG                     StringSize
);