typedef union _PCI_EXPRESS_PME_REQUESTOR_ID {
  struct {
    USHORT FunctionNumber  :3;
    USHORT DeviceNumber  :5;
    USHORT BusNumber  :3;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_PME_REQUESTOR_ID, *PPCI_EXPRESS_PME_REQUESTOR_ID;