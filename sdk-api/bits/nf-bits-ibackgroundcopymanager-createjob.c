HRESULT CreateJob(
  [in]  LPCWSTR            DisplayName,
  [in]  BG_JOB_TYPE        Type,
  [out] GUID               *pJobId,
  [out] IBackgroundCopyJob **ppJob
);