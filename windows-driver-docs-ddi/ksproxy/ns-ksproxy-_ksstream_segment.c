typedef struct _KSSTREAM_SEGMENT {
  IKsInterfaceHandler *KsInterfaceHandler;
  IKsDataTypeHandler  *KsDataTypeHandler;
  KSIOOPERATION       IoOperation;
  HANDLE              CompletionEvent;
} *PKSSTREAM_SEGMENT, KSSTREAM_SEGMENT;