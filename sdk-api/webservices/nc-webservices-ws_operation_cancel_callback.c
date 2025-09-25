WS_OPERATION_CANCEL_CALLBACK WsOperationCancelCallback;

void WsOperationCancelCallback(
  [in] const WS_SERVICE_CANCEL_REASON reason,
  [in] void *state
)
{...}