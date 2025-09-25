typedef struct MINIDUMP_EXCEPTION_STREAM {
  ULONG32                      ThreadId;
  ULONG32                      __alignment;
  MINIDUMP_EXCEPTION           ExceptionRecord;
  MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
} MINIDUMP_EXCEPTION_STREAM, *PMINIDUMP_EXCEPTION_STREAM;