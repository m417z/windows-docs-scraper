RPC_STATUS RpcBindingInqAuthClientExW(
  RPC_BINDING_HANDLE ClientBinding,
  RPC_AUTHZ_HANDLE   *Privs,
  RPC_WSTR           *ServerPrincName,
  unsigned long      *AuthnLevel,
  unsigned long      *AuthnSvc,
  unsigned long      *AuthzSvc,
  unsigned long      Flags
);