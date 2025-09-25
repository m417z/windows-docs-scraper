BOOL EvtGetQueryInfo(
  [in]  EVT_HANDLE            QueryOrSubscription,
  [in]  EVT_QUERY_PROPERTY_ID PropertyId,
  [in]  DWORD                 PropertyValueBufferSize,
  [in]  PEVT_VARIANT          PropertyValueBuffer,
  [out] PDWORD                PropertyValueBufferUsed
);