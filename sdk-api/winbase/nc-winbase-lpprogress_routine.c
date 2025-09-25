LPPROGRESS_ROUTINE LpprogressRoutine;

DWORD LpprogressRoutine(
  [in]           LARGE_INTEGER TotalFileSize,
  [in]           LARGE_INTEGER TotalBytesTransferred,
  [in]           LARGE_INTEGER StreamSize,
  [in]           LARGE_INTEGER StreamBytesTransferred,
  [in]           DWORD dwStreamNumber,
  [in]           DWORD dwCallbackReason,
  [in]           HANDLE hSourceFile,
  [in]           HANDLE hDestinationFile,
  [in, optional] LPVOID lpData
)
{...}