typedef struct _PosBarcodeScannerCapabilitiesType {
  DriverUnifiedPosPowerReportingType PowerReportingType;
  LONG                               IsStatisticsReportingSupported;
  LONG                               IsStatisticsUpdatingSupported;
  LONG                               IsImagePreviewSupported;
} PosBarcodeScannerCapabilitiesType;