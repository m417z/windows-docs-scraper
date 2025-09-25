EVT_WDF_INTERRUPT_DISABLE EvtWdfInterruptDisable;

NTSTATUS EvtWdfInterruptDisable(
  [in] WDFINTERRUPT Interrupt,
  [in] WDFDEVICE AssociatedDevice
)
{...}