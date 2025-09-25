typedef struct {
  ULONG                 Size;
  ULONG                 Version;
  ULONG                 GeofenceID;
  GNSS_GEOFENCE_STATE   GeofenceState;
  GNSS_FIXDATA_BASIC    FixBasicData;
  GNSS_FIXDATA_ACCURACY FixAccuracyData;
  BYTE                  Unused[512];
} GNSS_GEOFENCE_ALERT_DATA, *PGNSS_GEOFENCE_ALERT_DATA;