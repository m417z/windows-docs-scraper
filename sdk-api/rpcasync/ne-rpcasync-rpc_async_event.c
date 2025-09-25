typedef enum _RPC_ASYNC_EVENT {
  RpcCallComplete,
  RpcSendComplete,
  RpcReceiveComplete,
  RpcClientDisconnect,
  RpcClientCancel
} RPC_ASYNC_EVENT;