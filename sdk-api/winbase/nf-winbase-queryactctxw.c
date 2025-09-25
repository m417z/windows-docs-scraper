BOOL QueryActCtxW(
  [in]            DWORD  dwFlags,
  [in]            HANDLE hActCtx,
  [in, optional]  PVOID  pvSubInstance,
  [in]            ULONG  ulInfoClass,
  [out]           PVOID  pvBuffer,
  [in, optional]  SIZE_T cbBuffer,
  [out, optional] SIZE_T *pcbWrittenOrRequired
);