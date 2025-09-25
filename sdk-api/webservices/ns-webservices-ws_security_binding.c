typedef struct _WS_SECURITY_BINDING {
  WS_SECURITY_BINDING_TYPE     bindingType;
  WS_SECURITY_BINDING_PROPERTY *properties;
  ULONG                        propertyCount;
} WS_SECURITY_BINDING;