typedef union _PCI_EXPRESS_DPC_CAPS_REGISTER {
  struct {
    USHORT InterruptMsgNumber : 5;
    USHORT RpExtensionsForDpc : 1;
    USHORT PoisonedTlpEgressBlockingSupported : 1;
    USHORT DpcSoftwareTriggeringSupported : 1;
    USHORT RpPioLogSize : 4;
    USHORT DlActiveErrCorSignalingSupported : 1;
    USHORT Reserved : 3;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_DPC_CAPS_REGISTER, *PPCI_EXPRESS_DPC_CAPS_REGISTER;