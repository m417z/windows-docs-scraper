RPC_STATUS RpcBindingInqAuthInfo(
  RPC_BINDING_HANDLE       Binding,
  RPC_CSTR                 *ServerPrincName,
  unsigned long            *AuthnLevel,
  unsigned long            *AuthnSvc,
  RPC_AUTH_IDENTITY_HANDLE *AuthIdentity,
  unsigned long            *AuthzSvc
);