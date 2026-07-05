typedef union _PCI_EXPRESS_LINK_CONTROL_REGISTER {
  struct {
    USHORT ActiveStatePMControl : 2;
    USHORT Rsvd1 : 1;
    USHORT ReadCompletionBoundary : 1;
    USHORT LinkDisable : 1;
    USHORT RetrainLink : 1;
    USHORT CommonClockConfig : 1;
    USHORT ExtendedSynch : 1;
    USHORT EnableClockPowerManagement : 1;
    USHORT Rsvd2 : 1;
    USHORT BandwidthManagementInterrupt : 1;
    USHORT AutonomousBandwidthInterrupt : 1;
    USHORT Rsvd3 : 4;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_LINK_CONTROL_REGISTER, *PPCI_EXPRESS_LINK_CONTROL_REGISTER;