GPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION GpioClientQuerySetControllerInformation;

NTSTATUS GpioClientQuerySetControllerInformation(
  [in]            PVOID Context,
  [in]            PCLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT InputBuffer,
  [out, optional] PCLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT OutputBuffer
)
{...}