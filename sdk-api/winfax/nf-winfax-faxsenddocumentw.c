WINFAXAPI BOOL FaxSendDocumentW(
  [in]           HANDLE                    FaxHandle,
  [in]           LPCWSTR                   FileName,
  [in]           PFAX_JOB_PARAMW           JobParams,
  [in, optional] const FAX_COVERPAGE_INFOW *CoverpageInfo,
  [out]          LPDWORD                   FaxJobId
);