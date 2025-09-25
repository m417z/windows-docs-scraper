NTSTATUS IkeextSaGetById1(
  [in]            HANDLE             engineHandle,
  [in]            UINT64             id,
  [in., optional] GUID               *saLookupContext,
  [out]           IKEEXT_SA_DETAILS1 **sa
);