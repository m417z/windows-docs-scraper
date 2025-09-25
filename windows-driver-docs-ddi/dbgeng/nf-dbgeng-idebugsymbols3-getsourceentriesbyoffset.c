HRESULT GetSourceEntriesByOffset(
  [in]            ULONG64                    Offset,
  [in]            ULONG                      Flags,
  [out]           PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
  [in]            ULONG                      EntriesCount,
  [out, optional] PULONG                     EntriesAvail
);