typedef struct _WS_POLICY_CONSTRAINTS {
  WS_CHANNEL_BINDING             channelBinding;
  WS_CHANNEL_PROPERTY_CONSTRAINT *channelPropertyConstraints;
  ULONG                          channelPropertyConstraintCount;
  WS_SECURITY_CONSTRAINTS        *securityConstraints;
  WS_POLICY_EXTENSION            **policyExtensions;
  ULONG                          policyExtensionCount;
} WS_POLICY_CONSTRAINTS;