typedef struct {
  ULONG Size;
  ULONG Version;
  CHAR  NmeaSentences[256];
} GNSS_NMEA_DATA, *PGNSS_NMEA_DATA;