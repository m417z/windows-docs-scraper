HRESULT BeginRegisterPlatformWorkQueueWithMMCSSEx(
  [in] DWORD            dwPlatformWorkQueue,
  [in] LPCWSTR          wszClass,
  [in] DWORD            dwTaskId,
  [in] LONG             lPriority,
  [in] IMFAsyncCallback *pCallback,
  [in] IUnknown         *pState
);