typedef struct _WS_CUSTOM_TYPE_DESCRIPTION {
  ULONG                        size;
  ULONG                        alignment;
  WS_READ_TYPE_CALLBACK        readCallback;
  WS_WRITE_TYPE_CALLBACK       writeCallback;
  void                         *descriptionData;
  WS_IS_DEFAULT_VALUE_CALLBACK isDefaultValueCallback;
} WS_CUSTOM_TYPE_DESCRIPTION;