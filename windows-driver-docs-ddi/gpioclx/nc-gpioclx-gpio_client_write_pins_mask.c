GPIO_CLIENT_WRITE_PINS_MASK GpioClientWritePinsMask;

NTSTATUS GpioClientWritePinsMask(
  [in] PVOID Context,
  [in] PGPIO_WRITE_PINS_MASK_PARAMETERS WriteParameters
)
{...}