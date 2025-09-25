HRESULT GetSourceEntriesByLineWide(
  [in]            ULONG                      Line,
  [in]            PCWSTR                     File,
  [in]            ULONG                      Flags,
  [out, optional] PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
  [in]            ULONG                      EntriesCount,
  [out, optional] PULONG                     EntriesAvail
);