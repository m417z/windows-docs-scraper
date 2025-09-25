typedef struct SMHBA_ProtocolStatistics {
  HBA_INT64 SecondsSinceLastReset;
  HBA_INT64 InputRequests;
  HBA_INT64 OutputRequests;
  HBA_INT64 ControlRequests;
  HBA_INT64 InputMegabytes;
  HBA_INT64 OutputMegabytes;
} SMHBA_PROTOCOLSTATISTICS, *PSMHBA_PROTOCOLSTATISTICS;