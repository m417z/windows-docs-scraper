typedef struct _WWAN_CDMA_MRL_INFO {
  ULONG ServingCellFlag;
  ULONG NID;
  ULONG SID;
  ULONG BaseStationId;
  ULONG BaseLatitude;
  ULONG BaseLongitude;
  ULONG RefPn;
  ULONG GPSSeconds;
  ULONG PilotStrength;
} WWAN_CDMA_MRL_INFO, *PWWAN_CDMA_MRL_INFO;