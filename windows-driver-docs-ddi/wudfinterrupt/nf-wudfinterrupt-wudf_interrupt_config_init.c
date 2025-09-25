VOID WUDF_INTERRUPT_CONFIG_INIT(
  [out]          PWUDF_INTERRUPT_CONFIG      Configuration,
  [in]           PFN_WUDF_INTERRUPT_ISR      OnInterruptIsr,
  [in, optional] PFN_WUDF_INTERRUPT_WORKITEM OnInterruptWorkItem
);