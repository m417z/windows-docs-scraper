WINFAXAPI BOOL FaxSetJobW(
  [in] HANDLE               FaxHandle,
  [in] DWORD                JobId,
  [in] DWORD                Command,
  [in] const FAX_JOB_ENTRYW *JobEntry
);