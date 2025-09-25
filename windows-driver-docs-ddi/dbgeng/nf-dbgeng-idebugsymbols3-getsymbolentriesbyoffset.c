HRESULT GetSymbolEntriesByOffset(
  [in]            ULONG64              Offset,
  [in]            ULONG                Flags,
  [out, optional] PDEBUG_MODULE_AND_ID Ids,
  [out, optional] PULONG64             Displacements,
  [in]            ULONG                IdsCount,
  [out, optional] PULONG               Entries
);