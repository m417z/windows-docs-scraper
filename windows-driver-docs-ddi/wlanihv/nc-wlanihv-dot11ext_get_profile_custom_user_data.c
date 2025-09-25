DOT11EXT_GET_PROFILE_CUSTOM_USER_DATA Dot11extGetProfileCustomUserData;

DWORD Dot11extGetProfileCustomUserData(
  [in, optional] HANDLE hDot11SvcHandle,
  [in, optional] HANDLE hConnectSession,
  [in]           DWORD dwSessionID,
  [out]          DWORD *pdwDataSize,
  [out]          LPVOID *ppvData
)
{...}