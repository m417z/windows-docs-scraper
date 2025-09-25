typedef struct _WER_RUNTIME_EXCEPTION_INFORMATION {
  DWORD            dwSize;
  HANDLE           hProcess;
  HANDLE           hThread;
  EXCEPTION_RECORD exceptionRecord;
  CONTEXT          context;
  PCWSTR           pwszReportId;
  BOOL             bIsFatal;
  DWORD            dwReserved;
} WER_RUNTIME_EXCEPTION_INFORMATION, *PWER_RUNTIME_EXCEPTION_INFORMATION;