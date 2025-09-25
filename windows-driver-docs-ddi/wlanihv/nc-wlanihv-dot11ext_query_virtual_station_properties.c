DOT11EXT_QUERY_VIRTUAL_STATION_PROPERTIES Dot11extQueryVirtualStationProperties;

DWORD Dot11extQueryVirtualStationProperties(
  [in, optional] HANDLE hDot11SvcHandle,
  [out]          BOOL *pbIsVirtualStation,
  [out]          GUID *pgPrimary,
                 LPVOID pvReserved
)
{...}