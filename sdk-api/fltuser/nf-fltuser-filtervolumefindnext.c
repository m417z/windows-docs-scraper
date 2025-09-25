HRESULT FilterVolumeFindNext(
  [in]  HANDLE                          hVolumeFind,
  [in]  FILTER_VOLUME_INFORMATION_CLASS dwInformationClass,
  [out] LPVOID                          lpBuffer,
  [in]  DWORD                           dwBufferSize,
  [out] LPDWORD                         lpBytesReturned
);