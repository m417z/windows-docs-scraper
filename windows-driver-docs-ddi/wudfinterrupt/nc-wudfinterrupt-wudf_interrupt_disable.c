WUDF_INTERRUPT_DISABLE WudfInterruptDisable;

HRESULT WudfInterruptDisable(
  [in] IWDFInterrupt *Interrupt,
  [in] IWDFDevice *AssociatedDevice
)
{...}