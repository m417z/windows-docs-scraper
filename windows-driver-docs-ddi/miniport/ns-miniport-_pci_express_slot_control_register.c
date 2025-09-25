typedef union _PCI_EXPRESS_SLOT_CONTROL_REGISTER {
  struct {
    USHORT AttentionButtonEnable : 1;
    USHORT PowerFaultDetectEnable : 1;
    USHORT MRLSensorEnable : 1;
    USHORT PresenceDetectEnable : 1;
    USHORT CommandCompletedEnable : 1;
    USHORT HotPlugInterruptEnable : 1;
    USHORT AttentionIndicatorControl : 2;
    USHORT PowerIndicatorControl : 2;
    USHORT PowerControllerControl : 1;
    USHORT ElectromechanicalLockControl : 1;
    USHORT DataLinkStateChangeEnable : 1;
    USHORT Rsvd : 3;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} PCI_EXPRESS_SLOT_CONTROL_REGISTER, *PPCI_EXPRESS_SLOT_CONTROL_REGISTER;