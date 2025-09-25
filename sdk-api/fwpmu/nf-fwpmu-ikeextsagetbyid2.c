DWORD IkeextSaGetById2(
  [in]           HANDLE             engineHandle,
  [in]           UINT64             id,
  [in, optional] GUID               *saLookupContext,
  [out]          IKEEXT_SA_DETAILS2 **sa
);