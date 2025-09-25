HRESULT GetCspStatusFromOperations(
  [in, optional] IObjectId               *pAlgorithm,
  [in]           AlgorithmOperationFlags Operations,
  [out]          ICspStatus              **ppValue
);