typedef struct _TR_SERVICE_REQUEST_V1 {
  ULONG   InterfaceVersion;
  ULONG   ServiceMajorVersion;
  ULONG   ServiceMinorVersion;
  ULONG   FunctionCode;
  PVOID64 InputBuffer;
  ULONG64 InputBufferSize;
  PVOID64 OutputBuffer;
  ULONG64 OutputBufferSize;
} TR_SERVICE_REQUEST_V1, *PTR_SERVICE_REQUEST_V1;