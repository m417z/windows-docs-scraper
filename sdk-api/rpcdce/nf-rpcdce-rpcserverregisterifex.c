RPC_STATUS RpcServerRegisterIfEx(
  RPC_IF_HANDLE      IfSpec,
  UUID               *MgrTypeUuid,
  RPC_MGR_EPV        *MgrEpv,
  unsigned int       Flags,
  unsigned int       MaxCalls,
  RPC_IF_CALLBACK_FN *IfCallback
);