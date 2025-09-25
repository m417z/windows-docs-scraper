HRESULT EndGetStatusForMultipleOperations(
  [in]  const WSD_OPERATION  *pOperations,
  [in]  DWORD                dwOperationCount,
  [in]  IWSDAsyncResult      *pResult,
  [out] WSD_EVENTING_EXPIRES **ppExpires,
  [out] WSDXML_ELEMENT       **ppAny
);