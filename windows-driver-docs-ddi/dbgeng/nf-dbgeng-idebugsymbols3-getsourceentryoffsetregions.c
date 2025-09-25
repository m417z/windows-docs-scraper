HRESULT GetSourceEntryOffsetRegions(
  [in]            PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
  [in]            ULONG                      Flags,
  [out]           PDEBUG_OFFSET_REGION       Regions,
  [in]            ULONG                      RegionsCount,
  [out, optional] PULONG                     RegionsAvail
);