typedef struct _WS_SECURITY_BINDING_CONSTRAINT {
  WS_SECURITY_BINDING_CONSTRAINT_TYPE     type;
  WS_SECURITY_BINDING_PROPERTY_CONSTRAINT *propertyConstraints;
  ULONG                                   propertyConstraintCount;
} WS_SECURITY_BINDING_CONSTRAINT;