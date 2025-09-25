HRESULT BeginSubscribeToMultipleOperations(
  [in]  const WSD_OPERATION        *pOperations,
  [in]  DWORD                      dwOperationCount,
  [in]  IUnknown                   *pUnknown,
  [in]  const WSD_EVENTING_EXPIRES *pExpires,
  [in]  const WSDXML_ELEMENT       *pAny,
  [in]  IUnknown                   *pAsyncState,
  [in]  IWSDAsyncCallback          *pAsyncCallback,
  [out] IWSDAsyncResult            **ppResult
);