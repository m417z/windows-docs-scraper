GPIO_CLIENT_READ_PINS GpioClientReadPins;

NTSTATUS GpioClientReadPins(
  [in]      PVOID Context,
  [in, out] PGPIO_READ_PINS_PARAMETERS ReadParameters
)
{...}