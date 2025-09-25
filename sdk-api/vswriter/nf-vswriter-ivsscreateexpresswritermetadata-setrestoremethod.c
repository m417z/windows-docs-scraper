HRESULT SetRestoreMethod(
  [in] VSS_RESTOREMETHOD_ENUM method,
  [in] LPCWSTR                wszService,
  [in] LPCWSTR                wszUserProcedure,
  [in] VSS_WRITERRESTORE_ENUM writerRestore,
  [in] bool                   bRebootRequired
);