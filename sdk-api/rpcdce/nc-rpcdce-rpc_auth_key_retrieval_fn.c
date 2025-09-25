RPC_AUTH_KEY_RETRIEVAL_FN RpcAuthKeyRetrievalFn;

void RpcAuthKeyRetrievalFn(
  void *Arg,
  RPC_WSTR ServerPrincName,
  unsigned long KeyVer,
  void **Key,
  RPC_STATUS *Status
)
{...}