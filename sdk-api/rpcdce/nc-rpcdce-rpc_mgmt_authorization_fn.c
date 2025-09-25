RPC_MGMT_AUTHORIZATION_FN RpcMgmtAuthorizationFn;

int RpcMgmtAuthorizationFn(
  RPC_BINDING_HANDLE ClientBinding,
  unsigned long RequestedMgmtOperation,
  RPC_STATUS *Status
)
{...}