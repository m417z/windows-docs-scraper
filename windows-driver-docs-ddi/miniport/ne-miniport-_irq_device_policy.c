typedef enum _IRQ_DEVICE_POLICY {
  IrqPolicyMachineDefault,
  IrqPolicyAllCloseProcessors,
  IrqPolicyOneCloseProcessor,
  IrqPolicyAllProcessorsInMachine,
  IrqPolicySpecifiedProcessors,
  IrqPolicySpreadMessagesAcrossAllProcessors,
  IrqPolicyAllProcessorsInMachineWhenSteered
} IRQ_DEVICE_POLICY, *PIRQ_DEVICE_POLICY;