GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION GpioClientControllerSpecificFunction;

NTSTATUS GpioClientControllerSpecificFunction(
  [in]      PVOID Context,
  [in, out] PGPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS Parameters
)
{...}