PDH_FUNCTION PdhReadRawLogRecord(
  [in]  PDH_HLOG            hLog,
  [in]  FILETIME            ftRecord,
  [out] PPDH_RAW_LOG_RECORD pRawLogRecord,
  [in]  LPDWORD             pdwBufferLength
);