HRESULT GetRestoreMethod(
  [out] VSS_RESTOREMETHOD_ENUM *pMethod,
  [out] BSTR                   *pbstrService,
  [out] BSTR                   *pbstrUserProcedure,
  [out] VSS_WRITERRESTORE_ENUM *pwriterRestore,
  [out] bool                   *pbRebootRequired,
  [out] UINT                   *pcMappings
);