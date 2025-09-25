typedef struct _MINIDUMP_EXCEPTION {
  ULONG32 ExceptionCode;
  ULONG32 ExceptionFlags;
  ULONG64 ExceptionRecord;
  ULONG64 ExceptionAddress;
  ULONG32 NumberParameters;
  ULONG32 __unusedAlignment;
  ULONG64 ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
} MINIDUMP_EXCEPTION, *PMINIDUMP_EXCEPTION;