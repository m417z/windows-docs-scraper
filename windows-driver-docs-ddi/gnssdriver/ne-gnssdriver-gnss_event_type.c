typedef enum {
  GNSS_Event_FixAvailable,
  GNSS_Event_RequireAgnss,
  GNSS_Event_Error,
  GNSS_Event_NiRequest,
  GNSS_Event_NmeaData,
  GNSS_Event_GeofenceAlertData,
  GNSS_Event_GeofencesTrackingStatus,
  GNSS_Event_DriverRequest,
  GNSS_Event_BreadcrumbAlertEvent,
  GNSS_Event_FixAvailable_2,
  GNSS_Event_Custom
} GNSS_EVENT_TYPE;