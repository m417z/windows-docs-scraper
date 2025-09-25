RPC_STATUS RpcServerRegisterIf3(
  [in]           RPC_IF_HANDLE      IfSpec,
  [in, optional] UUID               *MgrTypeUuid,
  [in, optional] RPC_MGR_EPV        *MgrEpv,
  [in]           unsigned int       Flags,
  [in]           unsigned int       MaxCalls,
  [in]           unsigned int       MaxRpcSize,
  [in, optional] RPC_IF_CALLBACK_FN *IfCallback,
  [in, optional] void               *SecurityDescriptor
);