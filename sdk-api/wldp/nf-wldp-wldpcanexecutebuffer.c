HRESULT WldpCanExecuteBuffer(
  [in]           REFGUID                           host,
  [in]           WLDP_EXECUTION_EVALUATION_OPTIONS options,
  [in]           const BYTE                        *buffer,
  [in]           ULONG                             bufferSize,
  [in, optional] PCWSTR                            auditInfo,
  [out]          WLDP_EXECUTION_POLICY             *result
);