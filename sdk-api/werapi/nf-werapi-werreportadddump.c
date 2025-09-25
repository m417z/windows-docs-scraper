HRESULT WerReportAddDump(
  [in]           HREPORT                    hReportHandle,
  [in]           HANDLE                     hProcess,
  [in, optional] HANDLE                     hThread,
  [in]           WER_DUMP_TYPE              dumpType,
  [in, optional] PWER_EXCEPTION_INFORMATION pExceptionParam,
  [in, optional] PWER_DUMP_CUSTOM_OPTIONS   pDumpCustomOptions,
  [in]           DWORD                      dwFlags
);