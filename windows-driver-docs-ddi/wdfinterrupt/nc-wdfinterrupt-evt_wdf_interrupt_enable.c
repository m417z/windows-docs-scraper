EVT_WDF_INTERRUPT_ENABLE EvtWdfInterruptEnable;

NTSTATUS EvtWdfInterruptEnable(
  [in] WDFINTERRUPT Interrupt,
  [in] WDFDEVICE AssociatedDevice
)
{...}