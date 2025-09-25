BOOL GetNamedPipeInfo(
  [in]            HANDLE  hNamedPipe,
  [out, optional] LPDWORD lpFlags,
  [out, optional] LPDWORD lpOutBufferSize,
  [out, optional] LPDWORD lpInBufferSize,
  [out, optional] LPDWORD lpMaxInstances
);