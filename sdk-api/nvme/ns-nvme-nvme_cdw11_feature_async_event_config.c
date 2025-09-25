typedef union {
  struct {
    ULONG CriticalWarnings : 8;
    ULONG NsAttributeNotices : 1;
    ULONG FwActivationNotices : 1;
    ULONG TelemetryLogNotices : 1;
    ULONG ANAChangeNotices : 1;
    ULONG PredictableLogChangeNotices : 1;
    ULONG LBAStatusNotices : 1;
    ULONG EnduranceEventNotices : 1;
    ULONG Reserved0 : 12;
    ULONG ZoneDescriptorNotices : 1;
    ULONG Reserved1 : 4;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG, *PNVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG;