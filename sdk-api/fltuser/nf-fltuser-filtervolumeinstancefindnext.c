HRESULT FilterVolumeInstanceFindNext(
  [in]  HANDLE                     hVolumeInstanceFind,
  [in]  INSTANCE_INFORMATION_CLASS dwInformationClass,
  [out] LPVOID                     lpBuffer,
  [in]  DWORD                      dwBufferSize,
  [out] LPDWORD                    lpBytesReturned
);