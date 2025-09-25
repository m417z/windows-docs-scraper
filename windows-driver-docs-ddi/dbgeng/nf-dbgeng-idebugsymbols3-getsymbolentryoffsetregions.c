HRESULT GetSymbolEntryOffsetRegions(
  [in]            PDEBUG_MODULE_AND_ID Id,
  [in]            ULONG                Flags,
  [out]           PDEBUG_OFFSET_REGION Regions,
  [in]            ULONG                RegionsCount,
  [out, optional] PULONG               RegionsAvail
);