typedef union _PCI_EXPRESS_ROOT_ERROR_STATUS {
  struct {
    ULONG CorrectableErrorReceived : 1;
    ULONG MultipleCorrectableErrorsReceived : 1;
    ULONG UncorrectableErrorReceived : 1;
    ULONG MultipleUncorrectableErrorsReceived : 1;
    ULONG FirstUncorrectableFatal : 1;
    ULONG NonFatalErrorMessagesReceived : 1;
    ULONG FatalErrorMessagesReceived : 1;
    ULONG Reserved : 20;
    ULONG AdvancedErrorInterruptMessageNumber : 5;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_ROOT_ERROR_STATUS, *PPCI_EXPRESS_ROOT_ERROR_STATUS;