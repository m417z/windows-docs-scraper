GPIO_CLIENT_READ_PINS_MASK GpioClientReadPinsMask;

NTSTATUS GpioClientReadPinsMask(
  [in]      PVOID Context,
  [in, out] PGPIO_READ_PINS_MASK_PARAMETERS ReadParameters
)
{...}