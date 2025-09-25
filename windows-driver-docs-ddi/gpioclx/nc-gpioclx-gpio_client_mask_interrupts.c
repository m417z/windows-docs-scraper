GPIO_CLIENT_MASK_INTERRUPTS GpioClientMaskInterrupts;

NTSTATUS GpioClientMaskInterrupts(
  [in]      PVOID Context,
  [in, out] PGPIO_MASK_INTERRUPT_PARAMETERS MaskParameters
)
{...}