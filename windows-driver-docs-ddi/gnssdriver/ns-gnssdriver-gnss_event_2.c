typedef struct {
  ULONG           Size;
  ULONG           Version;
  GNSS_EVENT_TYPE EventType;
  ULONG           EventDataSize;
  BYTE            Unused[512];
  union {
    GNSS_FIXDATA                       FixData;
    GNSS_FIXDATA_2                     FixData2;
    GNSS_AGNSS_REQUEST_PARAM           AgnssRequest;
    GNSS_NI_REQUEST_PARAM              NiRequest;
    GNSS_ERRORINFO                     ErrorInformation;
    GNSS_NMEA_DATA                     NmeaData;
    GNSS_GEOFENCE_ALERT_DATA           GeofenceAlertData;
    GNSS_BREADCRUMBING_ALERT_DATA      BreadcrumbAlertData;
    GNSS_GEOFENCES_TRACKINGSTATUS_DATA GeofencesTrackingStatus;
    GNSS_DRIVER_REQUEST_DATA           DriverRequestData;
    BYTE                               CustomData[ANYSIZE_ARRAY];
  };
} GNSS_EVENT_2, *PGNSS_EVENT_2;