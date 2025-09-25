typedef struct AM_STREAM_INFO {
  REFERENCE_TIME tStart;
  REFERENCE_TIME tStop;
  DWORD          dwStartCookie;
  DWORD          dwStopCookie;
  DWORD          dwFlags;
} AM_STREAM_INFO;