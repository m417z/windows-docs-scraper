typedef enum _WDF_INTERRUPT_POLICY {
  WdfIrqPolicyMachineDefault = 0,
  WdfIrqPolicyAllCloseProcessors,
  WdfIrqPolicyOneCloseProcessor,
  WdfIrqPolicyAllProcessorsInMachine,
  WdfIrqPolicySpecifiedProcessors,
  WdfIrqPolicySpreadMessagesAcrossAllProcessors
} WDF_INTERRUPT_POLICY, *PWDF_INTERRUPT_POLICY;