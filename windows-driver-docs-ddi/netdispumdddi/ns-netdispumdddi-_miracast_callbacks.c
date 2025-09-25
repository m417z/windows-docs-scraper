typedef struct _MIRACAST_CALLBACKS {
  PFN_REPORT_SESSION_STATUS           ReportSessionStatus;
  PFN_MIRACAST_IO_CONTROL             MiracastIoControl;
  PFN_REPORT_STATISTIC                ReportStatistic;
  PFN_GET_NEXT_CHUNK_DATA             GetNextChunkData;
  PFN_REGISTER_DATARATE_NOTIFICATIONS RegisterForDataRateNotifications;
} MIRACAST_CALLBACKS, *PMIRACAST_CALLBACKS;