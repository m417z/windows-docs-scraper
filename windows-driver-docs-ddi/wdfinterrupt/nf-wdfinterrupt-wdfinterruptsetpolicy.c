VOID WdfInterruptSetPolicy(
  [in] WDFINTERRUPT           Interrupt,
  [in] WDF_INTERRUPT_POLICY   Policy,
  [in] WDF_INTERRUPT_PRIORITY Priority,
  [in] KAFFINITY              TargetProcessorSet
);