RPC_STATUS RpcBindingInqAuthInfoExA(
  RPC_BINDING_HANDLE       Binding,
  RPC_CSTR                 *ServerPrincName,
  unsigned long            *AuthnLevel,
  unsigned long            *AuthnSvc,
  RPC_AUTH_IDENTITY_HANDLE *AuthIdentity,
  unsigned long            *AuthzSvc,
  unsigned long            RpcQosVersion,
  RPC_SECURITY_QOS         *SecurityQOS
);