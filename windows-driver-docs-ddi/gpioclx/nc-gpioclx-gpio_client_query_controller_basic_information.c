GPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION GpioClientQueryControllerBasicInformation;

NTSTATUS GpioClientQueryControllerBasicInformation(
  [in]  PVOID Context,
  [out] PCLIENT_CONTROLLER_BASIC_INFORMATION Information
)
{...}