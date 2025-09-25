HRESULT MFPutWaitingWorkItem(
  [in]  HANDLE         hEvent,
  [in]  LONG           Priority,
  [in]  IMFAsyncResult *pResult,
  [out] MFWORKITEM_KEY *pKey
);