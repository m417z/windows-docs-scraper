DOT11EXT_SET_PROFILE_CUSTOM_USER_DATA Dot11extSetProfileCustomUserData;

DWORD Dot11extSetProfileCustomUserData(
  [in, optional] HANDLE hDot11SvcHandle,
  [in, optional] HANDLE hConnectSession,
  [in]           DWORD dwSessionID,
  [in]           DWORD dwDataSize,
  [in]           LPVOID pvData
)
{...}