HRESULT GetSymbolEntriesByNameWide(
  [in]            PCWSTR               Symbol,
  [in]            ULONG                Flags,
  [out, optional] PDEBUG_MODULE_AND_ID Ids,
  [in]            ULONG                IdsCount,
  [out, optional] PULONG               Entries
);