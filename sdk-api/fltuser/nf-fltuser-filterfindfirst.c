HRESULT FilterFindFirst(
  [in]  FILTER_INFORMATION_CLASS dwInformationClass,
  [out] LPVOID                   lpBuffer,
  [in]  DWORD                    dwBufferSize,
  [out] LPDWORD                  lpBytesReturned,
  [out] LPHANDLE                 lpFilterFind
);