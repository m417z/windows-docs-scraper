typedef struct _WS_SECURITY_DESCRIPTION {
  WS_SECURITY_BINDING  **securityBindings;
  ULONG                securityBindingCount;
  WS_SECURITY_PROPERTY *properties;
  ULONG                propertyCount;
} WS_SECURITY_DESCRIPTION;