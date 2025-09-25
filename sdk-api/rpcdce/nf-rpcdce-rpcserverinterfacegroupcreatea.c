RPC_STATUS RpcServerInterfaceGroupCreateA(
  [in]  RPC_INTERFACE_TEMPLATEA              *Interfaces,
  [in]  unsigned long                        NumIfs,
  [in]  RPC_ENDPOINT_TEMPLATEA               *Endpoints,
  [in]  unsigned long                        NumEndpoints,
  [in]  unsigned long                        IdlePeriod,
  [in]  RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN IdleCallbackFn,
  [in]  void                                 *IdleCallbackContext,
  [out] PRPC_INTERFACE_GROUP                 IfGroup
);