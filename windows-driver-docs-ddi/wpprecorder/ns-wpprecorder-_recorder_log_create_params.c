typedef struct _RECORDER_LOG_CREATE_PARAMS {
  ULONG                  Size;
  ULONG                  LogTag;
  ULONG                  TotalBufferSize;
  ULONG                  ErrorPartitionSize;
  ULONG_PTR              LogIdentifierAppendValue;
  BOOLEAN                LogIdentifierAppendValueSet;
  ULONG                  LogIdentifierSize;
  CHAR                   LogIdentifier[RECORDER_LOG_IDENTIFIER_MAX_CHARS];
  WPP_RECORDER_TRI_STATE UseTimeStamp;
  WPP_RECORDER_TRI_STATE PreciseTimeStamp;
} RECORDER_LOG_CREATE_PARAMS, *PRECORDER_LOG_CREATE_PARAMS;