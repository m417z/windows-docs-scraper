HRESULT MigrateDisks(
  [in]  VDS_OBJECT_ID *pDiskArray,
  [in]  LONG          lNumberOfDisks,
  [in]  VDS_OBJECT_ID TargetPack,
  [in]  BOOL          bForce,
  [in]  BOOL          bQueryOnly,
  [out] HRESULT       *pResults,
  [out] BOOL          *pbRebootNeeded
);