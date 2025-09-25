BOOL EvtGetLogInfo(
  [in]  EVT_HANDLE          Log,
  [in]  EVT_LOG_PROPERTY_ID PropertyId,
  [in]  DWORD               PropertyValueBufferSize,
  [in]  PEVT_VARIANT        PropertyValueBuffer,
  [out] PDWORD              PropertyValueBufferUsed
);