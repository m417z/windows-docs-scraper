HRESULT WldpCanExecuteStream(
  [in]           REFGUID                           host,
  [in]           WLDP_EXECUTION_EVALUATION_OPTIONS options,
                 IStream                           *stream,
  [in, optional] PCWSTR                            auditInfo,
  [out]          WLDP_EXECUTION_POLICY             *result
);