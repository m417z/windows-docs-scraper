typedef struct {
  ULONG              Size;
  ULONG              Version;
  ULONG              SatelliteCount;
  GNSS_SATELLITEINFO SatelliteArray[GNSS_MAXSATELLITE];
} GNSS_FIXDATA_SATELLITE, *PGNSS_FIXDATA_SATELLITE;