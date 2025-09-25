DOT11EXT_SET_VIRTUAL_STATION_AP_PROPERTIES Dot11extSetVirtualStationApProperties;

DWORD Dot11extSetVirtualStationApProperties(
  [in, optional] HANDLE hDot11SvcHandle,
  [in, optional] HANDLE hConnectSession,
  [in]           DWORD dwNumProperties,
  [in]           PDOT11EXT_VIRTUAL_STATION_AP_PROPERTY pProperties,
                 LPVOID pvReserved
)
{...}