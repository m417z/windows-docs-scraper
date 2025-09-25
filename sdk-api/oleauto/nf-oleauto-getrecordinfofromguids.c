HRESULT GetRecordInfoFromGuids(
  [in]  REFGUID     rGuidTypeLib,
  [in]  ULONG       uVerMajor,
  [in]  ULONG       uVerMinor,
  [in]  LCID        lcid,
  [in]  REFGUID     rGuidTypeInfo,
  [out] IRecordInfo **ppRecInfo
);