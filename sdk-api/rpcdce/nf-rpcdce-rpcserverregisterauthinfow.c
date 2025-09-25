RPC_STATUS RpcServerRegisterAuthInfoW(
  RPC_WSTR                  ServerPrincName,
  unsigned long             AuthnSvc,
  RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,
  void                      *Arg
);