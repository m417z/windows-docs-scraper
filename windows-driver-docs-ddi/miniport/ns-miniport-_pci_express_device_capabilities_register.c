typedef union _PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER {
  struct {
    ULONG MaxPayloadSizeSupported : 3;
    ULONG PhantomFunctionsSupported : 2;
    ULONG ExtendedTagSupported : 1;
    ULONG L0sAcceptableLatency : 3;
    ULONG L1AcceptableLatency : 3;
    ULONG Undefined : 3;
    ULONG RoleBasedErrorReporting : 1;
    ULONG Rsvd1 : 2;
    ULONG CapturedSlotPowerLimit : 8;
    ULONG CapturedSlotPowerLimitScale : 2;
    ULONG FunctionLevelResetCapability : 1;
    ULONG Rsvd2 : 3;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER, *PPCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER;