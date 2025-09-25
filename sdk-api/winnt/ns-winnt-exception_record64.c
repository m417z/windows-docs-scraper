typedef struct _EXCEPTION_RECORD64 {
  DWORD   ExceptionCode;
  DWORD   ExceptionFlags;
  DWORD64 ExceptionRecord;
  DWORD64 ExceptionAddress;
  DWORD   NumberParameters;
  DWORD   __unusedAlignment;
  DWORD64 ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
} EXCEPTION_RECORD64, *PEXCEPTION_RECORD64;