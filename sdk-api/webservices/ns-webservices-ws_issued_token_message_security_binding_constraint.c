typedef struct _WS_ISSUED_TOKEN_MESSAGE_SECURITY_BINDING_CONSTRAINT {
  WS_SECURITY_BINDING_CONSTRAINT                bindingConstraint;
  WS_MESSAGE_SECURITY_USAGE                     bindingUsage;
  WS_XML_STRING                                 *claimConstraints;
  ULONG                                         claimConstraintCount;
  WS_REQUEST_SECURITY_TOKEN_PROPERTY_CONSTRAINT *requestSecurityTokenPropertyConstraints;
  ULONG                                         requestSecurityTokenPropertyConstraintCount;
  struct {
    WS_ENDPOINT_ADDRESS *issuerAddress;
    WS_XML_BUFFER       *requestSecurityTokenTemplate;
  } out;
} WS_ISSUED_TOKEN_MESSAGE_SECURITY_BINDING_CONSTRAINT;