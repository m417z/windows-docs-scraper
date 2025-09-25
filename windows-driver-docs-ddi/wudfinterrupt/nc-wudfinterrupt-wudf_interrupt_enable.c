WUDF_INTERRUPT_ENABLE WudfInterruptEnable;

HRESULT WudfInterruptEnable(
  [in] IWDFInterrupt *Interrupt,
  [in] IWDFDevice *AssociatedDevice
)
{...}