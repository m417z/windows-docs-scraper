typedef struct tagDIAGNOSTIC_DATA_GENERAL_STATS {
  UINT32 optInLevel;
  UINT64 transcriptSizeBytes;
  UINT64 oldestEventTimestamp;
  UINT32 totalEventCountLast24Hours;
  FLOAT  averageDailyEvents;
} DIAGNOSTIC_DATA_GENERAL_STATS;