typedef struct {
  ULONG    Size;
  ULONG    Version;
  NTSTATUS CreationStatus;
  ULONG    GeofenceID;
  BYTE     Unused[512];
} GNSS_GEOFENCE_CREATE_RESPONSE, *PGNSS_GEOFENCE_CREATE_RESPONSE;