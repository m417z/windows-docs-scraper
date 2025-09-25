RPC_STATUS RpcServerRegisterIf2(
  RPC_IF_HANDLE      IfSpec,
  UUID               *MgrTypeUuid,
  RPC_MGR_EPV        *MgrEpv,
  unsigned int       Flags,
  unsigned int       MaxCalls,
  unsigned int       MaxRpcSize,
  RPC_IF_CALLBACK_FN *IfCallbackFn
);