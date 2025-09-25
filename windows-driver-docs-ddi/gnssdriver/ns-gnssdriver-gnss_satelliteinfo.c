typedef struct {
  ULONG  SatelliteId;
  BOOL   UsedInPositiong;
  double Elevation;
  double Azimuth;
  double SignalToNoiseRatio;
} GNSS_SATELLITEINFO, *PGNSS_SATELLITEINFO;