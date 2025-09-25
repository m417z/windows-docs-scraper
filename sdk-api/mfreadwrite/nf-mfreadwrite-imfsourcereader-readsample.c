HRESULT ReadSample(
  [in]  DWORD     dwStreamIndex,
  [in]  DWORD     dwControlFlags,
  [out] DWORD     *pdwActualStreamIndex,
  [out] DWORD     *pdwStreamFlags,
  [out] LONGLONG  *pllTimestamp,
  [out] IMFSample **ppSample
);