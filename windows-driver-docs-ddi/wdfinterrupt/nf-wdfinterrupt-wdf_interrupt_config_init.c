VOID WDF_INTERRUPT_CONFIG_INIT(
  [out]          PWDF_INTERRUPT_CONFIG Configuration,
  [in]           PFN_WDF_INTERRUPT_ISR EvtInterruptIsr,
  [in, optional] PFN_WDF_INTERRUPT_DPC EvtInterruptDpc
);