typedef struct _HTTP_REQUEST_TIMING_INFO {
  ULONG     RequestTimingCount;
  ULONGLONG RequestTiming[HttpRequestTimingTypeMax];
} HTTP_REQUEST_TIMING_INFO, *PHTTP_REQUEST_TIMING_INFO;