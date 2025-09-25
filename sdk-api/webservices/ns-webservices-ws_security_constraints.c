typedef struct _WS_SECURITY_CONSTRAINTS {
  WS_SECURITY_PROPERTY_CONSTRAINT *securityPropertyConstraints;
  ULONG                           securityPropertyConstraintCount;
  WS_SECURITY_BINDING_CONSTRAINT  **securityBindingConstraints;
  ULONG                           securityBindingConstraintCount;
} WS_SECURITY_CONSTRAINTS;