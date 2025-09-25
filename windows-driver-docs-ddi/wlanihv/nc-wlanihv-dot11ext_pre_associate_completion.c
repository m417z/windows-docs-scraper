DOT11EXT_PRE_ASSOCIATE_COMPLETION Dot11extPreAssociateCompletion;

DWORD Dot11extPreAssociateCompletion(
  [in, optional] HANDLE hDot11SvcHandle,
  [in, optional] HANDLE hConnectSession,
  [in]           DWORD dwReasonCode,
  [in]           DWORD dwWin32Error
)
{...}