DXGKDDI_CONTROLINTERRUPT DxgkddiControlinterrupt;

NTSTATUS DxgkddiControlinterrupt(
  [in] IN_CONST_HANDLE hAdapter,
  [in] IN_CONST_DXGK_INTERRUPT_TYPE InterruptType,
  [in] IN_BOOLEAN EnableInterrupt
)
{...}