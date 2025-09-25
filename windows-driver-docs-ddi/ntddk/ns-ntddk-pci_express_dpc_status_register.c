typedef union _PCI_EXPRESS_DPC_STATUS_REGISTER {
  struct {
    USHORT TriggerStatus : 1;
    USHORT TriggerReason : 2;
    USHORT InterruptStatus : 1;
    USHORT RpBusy : 1;
    USHORT TriggerReasonExtension : 2;
    USHORT Reserved1 : 1;
    USHORT PioFirstErrPointer : 5;
    USHORT Reserved2 : 3;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_DPC_STATUS_REGISTER, *PPCI_EXPRESS_DPC_STATUS_REGISTER;