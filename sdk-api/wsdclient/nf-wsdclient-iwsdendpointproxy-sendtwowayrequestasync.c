HRESULT SendTwoWayRequestAsync(
  [in]  const void          *pBody,
  [in]  const WSD_OPERATION *pOperation,
  [in]  IUnknown            *pAsyncState,
  [in]  IWSDAsyncCallback   *pCallback,
  [out] IWSDAsyncResult     **pResult
);