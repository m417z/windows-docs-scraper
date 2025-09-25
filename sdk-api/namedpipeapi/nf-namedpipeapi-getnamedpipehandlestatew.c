BOOL GetNamedPipeHandleStateW(
  [in]            HANDLE  hNamedPipe,
  [out, optional] LPDWORD lpState,
  [out, optional] LPDWORD lpCurInstances,
  [out, optional] LPDWORD lpMaxCollectionCount,
  [out, optional] LPDWORD lpCollectDataTimeout,
  [out, optional] LPWSTR  lpUserName,
  [in]            DWORD   nMaxUserNameSize
);