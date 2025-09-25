RPC_STATUS RpcBindingInqAuthClientEx(
  RPC_BINDING_HANDLE ClientBinding,
  RPC_AUTHZ_HANDLE   *Privs,
  RPC_CSTR           *ServerPrincName,
  unsigned long      *AuthnLevel,
  unsigned long      *AuthnSvc,
  unsigned long      *AuthzSvc,
  unsigned long      Flags
);