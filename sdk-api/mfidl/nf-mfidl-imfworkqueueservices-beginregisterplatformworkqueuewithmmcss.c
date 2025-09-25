HRESULT BeginRegisterPlatformWorkQueueWithMMCSS(
  [in] DWORD            dwPlatformWorkQueue,
  [in] LPCWSTR          wszClass,
  [in] DWORD            dwTaskId,
  [in] IMFAsyncCallback *pCallback,
  [in] IUnknown         *pState
);