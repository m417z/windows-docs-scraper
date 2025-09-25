typedef struct _WS_SECURITY_BINDING_PROPERTY_CONSTRAINT {
  WS_SECURITY_BINDING_PROPERTY_ID id;
  void                            *allowedValues;
  ULONG                           allowedValuesSize;
  struct {
    WS_SECURITY_BINDING_PROPERTY securityBindingProperty;
  } out;
} WS_SECURITY_BINDING_PROPERTY_CONSTRAINT;