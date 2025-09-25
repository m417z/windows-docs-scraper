HRESULT MFBeginRegisterWorkQueueWithMMCSSEx(
  [in] DWORD            dwWorkQueueId,
  [in] LPCWSTR          wszClass,
  [in] DWORD            dwTaskId,
  [in] LONG             lPriority,
  [in] IMFAsyncCallback *pDoneCallback,
  [in] IUnknown         *pDoneState
);