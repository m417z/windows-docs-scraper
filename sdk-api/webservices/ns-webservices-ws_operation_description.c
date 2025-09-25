typedef struct _WS_OPERATION_DESCRIPTION {
  ULONG                    versionInfo;
  WS_MESSAGE_DESCRIPTION   *inputMessageDescription;
  WS_MESSAGE_DESCRIPTION   *outputMessageDescription;
  ULONG                    inputMessageOptions;
  ULONG                    outputMessageOptions;
  USHORT                   parameterCount;
  WS_PARAMETER_DESCRIPTION *parameterDescription;
  WS_SERVICE_STUB_CALLBACK stubCallback;
  WS_OPERATION_STYLE       style;
} WS_OPERATION_DESCRIPTION;