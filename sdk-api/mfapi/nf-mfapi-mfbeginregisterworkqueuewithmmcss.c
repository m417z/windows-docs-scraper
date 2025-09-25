HRESULT MFBeginRegisterWorkQueueWithMMCSS(
  [in] DWORD            dwWorkQueueId,
  [in] LPCWSTR          wszClass,
  [in] DWORD            dwTaskId,
  [in] IMFAsyncCallback *pDoneCallback,
  [in] IUnknown         *pDoneState
);