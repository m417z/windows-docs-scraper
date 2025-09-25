typedef struct _WS_REQUEST_SECURITY_TOKEN_PROPERTY_CONSTRAINT {
  WS_REQUEST_SECURITY_TOKEN_PROPERTY_ID id;
  void                                  *allowedValues;
  ULONG                                 allowedValuesSize;
  struct {
    WS_REQUEST_SECURITY_TOKEN_PROPERTY requestSecurityTokenProperty;
  } out;
} WS_REQUEST_SECURITY_TOKEN_PROPERTY_CONSTRAINT;