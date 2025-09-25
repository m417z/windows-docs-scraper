typedef struct {
  ULONG               Size;
  ULONG               Version;
  ULONG               AlertTypes;
  GNSS_GEOFENCE_STATE InitialState;
  GNSS_GEOREGION      Boundary;
  BYTE                Unused[512];
} GNSS_GEOFENCE_CREATE_PARAM, *PGNSS_GEOFENCE_CREATE_PARAM;