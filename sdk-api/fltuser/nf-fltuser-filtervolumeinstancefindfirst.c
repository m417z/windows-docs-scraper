HRESULT FilterVolumeInstanceFindFirst(
  [in]  LPCWSTR                    lpVolumeName,
  [in]  INSTANCE_INFORMATION_CLASS dwInformationClass,
  [out] LPVOID                     lpBuffer,
  [in]  DWORD                      dwBufferSize,
  [out] LPDWORD                    lpBytesReturned,
  [out] LPHANDLE                   lpVolumeInstanceFind
);