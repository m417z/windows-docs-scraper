DOT11EXT_SET_CURRENT_PROFILE Dot11extSetCurrentProfile;

DWORD Dot11extSetCurrentProfile(
  [in, optional] HANDLE hDot11SvcHandle,
  [in, optional] HANDLE hConnectSession,
  [in, optional] PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  [in, optional] PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile
)
{...}