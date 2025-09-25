typedef struct _WS_SECURITY_PROPERTY_CONSTRAINT {
  WS_SECURITY_PROPERTY_ID id;
  void                    *allowedValues;
  ULONG                   allowedValuesSize;
  struct {
    WS_SECURITY_PROPERTY securityProperty;
  } out;
} WS_SECURITY_PROPERTY_CONSTRAINT;