typedef enum _WDF_INTERRUPT_POLICY {
  WdfIrqPolicyMachineDefault,
  WdfIrqPolicyAllCloseProcessors,
  WdfIrqPolicyOneCloseProcessor,
  WdfIrqPolicyAllProcessorsInMachine,
  WdfIrqPolicySpecifiedProcessors,
  WdfIrqPolicySpreadMessagesAcrossAllProcessors
} WDF_INTERRUPT_POLICY, *PWDF_INTERRUPT_POLICY;