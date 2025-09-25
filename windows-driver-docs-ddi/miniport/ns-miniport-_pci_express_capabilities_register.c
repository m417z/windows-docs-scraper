typedef union _PCI_EXPRESS_CAPABILITIES_REGISTER {
  struct {
    USHORT CapabilityVersion : 4;
    USHORT DeviceType : 4;
    USHORT SlotImplemented : 1;
    USHORT InterruptMessageNumber : 5;
    USHORT Rsvd : 2;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_CAPABILITIES_REGISTER, *PPCI_EXPRESS_CAPABILITIES_REGISTER;