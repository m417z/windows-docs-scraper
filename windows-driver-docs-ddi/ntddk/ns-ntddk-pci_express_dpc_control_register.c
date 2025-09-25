typedef union _PCI_EXPRESS_DPC_CONTROL_REGISTER {
  struct {
    USHORT TriggerEnable : 2;
    USHORT CompletionControl : 1;
    USHORT InterruptEnable : 1;
    USHORT ErrCorEnable : 1;
    USHORT PoisonedTlpEgressBlockingEnable : 1;
    USHORT SoftwareTrigger : 1;
    USHORT DlActiveErrCorEnable : 1;
    USHORT Reserved : 8;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_DPC_CONTROL_REGISTER, *PPCI_EXPRESS_DPC_CONTROL_REGISTER;