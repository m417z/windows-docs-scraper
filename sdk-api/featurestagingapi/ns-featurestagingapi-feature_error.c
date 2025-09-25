typedef struct FEATURE_ERROR {
  HRESULT hr;
  UINT16  lineNumber;
  PCSTR   file;
  PCSTR   process;
  PCSTR   module;
  UINT32  callerReturnAddressOffset;
  PCSTR   callerModule;
  PCSTR   message;
  UINT16  originLineNumber;
  PCSTR   originFile;
  PCSTR   originModule;
  UINT32  originCallerReturnAddressOffset;
  PCSTR   originCallerModule;
  PCSTR   originName;
} FEATURE_ERROR;