typedef struct {
  ULONG                   Size;
  ULONG                   Version;
  ULONG                   FixSessionID;
  FILETIME                FixTimeStamp;
  BOOL                    IsFinalFix;
  NTSTATUS                FixStatus;
  ULONG                   FixLevelOfDetails;
  GNSS_FIXDATA_BASIC_2    BasicData;
  GNSS_FIXDATA_ACCURACY_2 AccuracyData;
  GNSS_FIXDATA_SATELLITE  SatelliteData;
} GNSS_FIXDATA_2, *PGNSS_FIXDATA_2;