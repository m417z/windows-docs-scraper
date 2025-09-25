HRESULT GetRecoverableErrorDataForChangeUnit(
  [in]  ISyncChangeUnit       *pChangeUnit,
  [out] HRESULT               *phrError,
  [out] IRecoverableErrorData **ppErrorData
);