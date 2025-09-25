RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN RpcInterfaceGroupIdleCallbackFn;

void RpcInterfaceGroupIdleCallbackFn(
  [in] RPC_INTERFACE_GROUP IfGroup,
  [in] void *IdleCallbackContext,
  [in] unsigned long IsGroupIdle
)
{...}