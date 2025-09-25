HRESULT OnStatus(
  [in] IBackgroundCopyGroup *pGroup,
  [in] IBackgroundCopyJob1  *pJob,
  [in] DWORD                dwFileIndex,
  [in] DWORD                dwStatus,
  [in] DWORD                dwNumOfRetries,
  [in] DWORD                dwWin32Result,
  [in] DWORD                dwTransportResult
);