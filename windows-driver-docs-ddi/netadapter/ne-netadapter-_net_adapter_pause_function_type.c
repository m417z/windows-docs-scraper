typedef enum _NET_ADAPTER_PAUSE_FUNCTION_TYPE {
  NetAdapterPauseFunctionTypeUnsupported = 0,
  NetAdapterPauseFunctionTypeSendOnly = 1,
  NetAdapterPauseFunctionTypeReceiveOnly = 2,
  NetAdapterPauseFunctionTypeSendAndReceive = 3,
  NetAdapterPauseFunctionTypeUnknown = 4
} NET_ADAPTER_PAUSE_FUNCTION_TYPE;