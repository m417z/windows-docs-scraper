int WPUQueueApc(
  [in]  LPWSATHREADID lpThreadId,
  [in]  LPWSAUSERAPC  lpfnUserApc,
  [in]  DWORD_PTR     dwContext,
  [out] LPINT         lpErrno
);