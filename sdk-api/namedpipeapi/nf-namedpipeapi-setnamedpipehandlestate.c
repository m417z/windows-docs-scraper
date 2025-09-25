BOOL SetNamedPipeHandleState(
  [in]           HANDLE  hNamedPipe,
  [in, optional] LPDWORD lpMode,
  [in, optional] LPDWORD lpMaxCollectionCount,
  [in, optional] LPDWORD lpCollectDataTimeout
);