typedef union _PCI_EXPRESS_ROOT_ERROR_COMMAND {
  struct {
    ULONG CorrectableErrorReportingEnable : 1;
    ULONG NonFatalErrorReportingEnable : 1;
    ULONG FatalErrorReportingEnable : 1;
    ULONG Reserved : 29;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_ROOT_ERROR_COMMAND, *PPCI_EXPRESS_ROOT_ERROR_COMMAND;