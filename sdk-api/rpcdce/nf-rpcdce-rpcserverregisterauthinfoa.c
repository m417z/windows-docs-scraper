RPC_STATUS RpcServerRegisterAuthInfoA(
  RPC_CSTR                  ServerPrincName,
  unsigned long             AuthnSvc,
  RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,
  void                      *Arg
);