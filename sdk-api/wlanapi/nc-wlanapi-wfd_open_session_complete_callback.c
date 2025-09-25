WFD_OPEN_SESSION_COMPLETE_CALLBACK WfdOpenSessionCompleteCallback;

VOID WfdOpenSessionCompleteCallback(
  [in] HANDLE hSessionHandle,
  [in] PVOID pvContext,
  [in] GUID guidSessionInterface,
  [in] DWORD dwError,
  [in] DWORD dwReasonCode
)
{...}