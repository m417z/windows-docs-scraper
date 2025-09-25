HRESULT GetSourceEntriesByLine(
  [in]                    ULONG                      Line,
  [in]                    PCSTR                      File,
  [in]                    ULONG                      Flags,
  [out, writes, optional] PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
  [in]                    ULONG                      EntriesCount,
  [out, optional]         PULONG                     EntriesAvail
);