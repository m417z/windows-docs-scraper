WINFAXAPI BOOL FaxSendDocumentA(
  [in]           HANDLE                    FaxHandle,
  [in]           LPCSTR                    FileName,
  [in]           PFAX_JOB_PARAMA           JobParams,
  [in, optional] const FAX_COVERPAGE_INFOA *CoverpageInfo,
  [out]          LPDWORD                   FaxJobId
);