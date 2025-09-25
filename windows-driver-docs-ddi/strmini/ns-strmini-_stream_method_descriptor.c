typedef struct _STREAM_METHOD_DESCRIPTOR {
  ULONG     MethodSetID;
  PKSMETHOD Method;
  PVOID     MethodInfo;
  LONG      MethodInputSize;
  LONG      MethodOutputSize;
} STREAM_METHOD_DESCRIPTOR, *PSTREAM_METHOD_DESCRIPTOR;