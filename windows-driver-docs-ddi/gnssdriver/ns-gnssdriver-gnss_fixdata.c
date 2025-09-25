typedef struct {
  ULONG                  Size;
  ULONG                  Version;
  ULONG                  FixSessionID;
  FILETIME               FixTimeStamp;
  BOOL                   IsFinalFix;
  NTSTATUS               FixStatus;
  ULONG                  FixLevelOfDetails;
  GNSS_FIXDATA_BASIC     BasicData;
  GNSS_FIXDATA_ACCURACY  AccuracyData;
  GNSS_FIXDATA_SATELLITE SatelliteData;
} GNSS_FIXDATA, *PGNSS_FIXDATA;