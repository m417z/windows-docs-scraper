HRESULT WldpCanExecuteFile(
  [in]           REFGUID                           host,
  [in]           WLDP_EXECUTION_EVALUATION_OPTIONS options,
  [in]           HANDLE                            fileHandle,
  [in, optional] PCWSTR                            auditInfo,
  [out]          WLDP_EXECUTION_POLICY             *result
);