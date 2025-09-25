typedef struct _PDH_RAW_LOG_RECORD {
  DWORD dwStructureSize;
  DWORD dwRecordType;
  DWORD dwItems;
  UCHAR RawBytes[1];
} PDH_RAW_LOG_RECORD, *PPDH_RAW_LOG_RECORD;