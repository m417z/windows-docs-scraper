DWORD XInputGetAudioDeviceIds(
  [in]                DWORD  dwUserIndex,
  [out, optional]     LPWSTR pRenderDeviceId,
  [in, out, optional] UINT   *pRenderCount,
  [out, optional]     LPWSTR pCaptureDeviceId,
  [in, out, optional] UINT   *pCaptureCount
);