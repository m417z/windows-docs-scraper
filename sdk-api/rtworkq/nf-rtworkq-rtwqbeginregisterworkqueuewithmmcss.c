HRESULT RtwqBeginRegisterWorkQueueWithMMCSS(
  [in] DWORD              workQueueId,
  [in] PCWSTR             usageClass,
  [in] DWORD              dwTaskId,
  [in] LONG               lPriority,
  [in] IRtwqAsyncCallback *doneCallback,
  [in] IUnknown           *doneState
);