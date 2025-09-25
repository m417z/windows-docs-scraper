typedef union _PCI_EXPRESS_DEVICE_STATUS_REGISTER {
  struct {
    USHORT CorrectableErrorDetected : 1;
    USHORT NonFatalErrorDetected : 1;
    USHORT FatalErrorDetected : 1;
    USHORT UnsupportedRequestDetected : 1;
    USHORT AuxPowerDetected : 1;
    USHORT TransactionsPending : 1;
    USHORT Rsvd : 10;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_DEVICE_STATUS_REGISTER, *PPCI_EXPRESS_DEVICE_STATUS_REGISTER;