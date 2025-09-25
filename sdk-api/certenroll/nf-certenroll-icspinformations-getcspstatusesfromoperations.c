HRESULT GetCspStatusesFromOperations(
  [in]           AlgorithmOperationFlags Operations,
  [in, optional] ICspInformation         *pCspInformation,
  [out]          ICspStatuses            **ppValue
);