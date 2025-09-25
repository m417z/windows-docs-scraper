HRESULT GetStatusForMultipleOperations(
  [in]  const WSD_OPERATION  *pOperations,
  [in]  DWORD                dwOperationCount,
  [in]  const WSDXML_ELEMENT *pAny,
  [out] WSD_EVENTING_EXPIRES **ppExpires,
  [out] WSDXML_ELEMENT       **ppAny
);