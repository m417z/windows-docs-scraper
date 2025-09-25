RPC_STATUS RpcServerInterfaceGroupCreateW(
  [in]  RPC_INTERFACE_TEMPLATEW              *Interfaces,
  [in]  unsigned long                        NumIfs,
  [in]  RPC_ENDPOINT_TEMPLATEW               *Endpoints,
  [in]  unsigned long                        NumEndpoints,
  [in]  unsigned long                        IdlePeriod,
  [in]  RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN IdleCallbackFn,
  [in]  void                                 *IdleCallbackContext,
  [out] PRPC_INTERFACE_GROUP                 IfGroup
);