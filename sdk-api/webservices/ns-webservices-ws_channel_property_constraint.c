typedef struct _WS_CHANNEL_PROPERTY_CONSTRAINT {
  WS_CHANNEL_PROPERTY_ID id;
  void                   *allowedValues;
  ULONG                  allowedValuesSize;
  struct {
    WS_CHANNEL_PROPERTY channelProperty;
  } out;
} WS_CHANNEL_PROPERTY_CONSTRAINT;