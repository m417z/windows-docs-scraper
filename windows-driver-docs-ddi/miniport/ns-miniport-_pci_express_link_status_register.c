typedef union _PCI_EXPRESS_LINK_STATUS_REGISTER {
  struct {
    USHORT LinkSpeed : 4;
    USHORT LinkWidth : 6;
    USHORT Undefined : 1;
    USHORT LinkTraining : 1;
    USHORT SlotClockConfig : 1;
    USHORT DataLinkLayerActive : 1;
    USHORT BandwidthManagementStatus : 1;
    USHORT AutonomousManagementStatus : 1;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_LINK_STATUS_REGISTER, *PPCI_EXPRESS_LINK_STATUS_REGISTER;