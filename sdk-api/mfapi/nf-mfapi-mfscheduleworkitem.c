HRESULT MFScheduleWorkItem(
  [in]  IMFAsyncCallback *pCallback,
  [in]  IUnknown         *pState,
  [in]  INT64            Timeout,
  [out] MFWORKITEM_KEY   *pKey
);