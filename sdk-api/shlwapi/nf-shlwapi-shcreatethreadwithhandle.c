BOOL SHCreateThreadWithHandle(
  [in]            LPTHREAD_START_ROUTINE pfnThreadProc,
  [in, optional]  void                   *pData,
  [in]            SHCT_FLAGS             flags,
  [in, optional]  LPTHREAD_START_ROUTINE pfnCallback,
  [out, optional] HANDLE                 *pHandle
);