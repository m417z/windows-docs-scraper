typedef union _PCI_EXPRESS_DEVICE_CONTROL_REGISTER {
  struct {
    USHORT CorrectableErrorEnable  :1;
    USHORT NonFatalErrorEnable  :1;
    USHORT FatalErrorEnable  :1;
    USHORT UnsupportedRequestErrorEnable  :1;
    USHORT EnableRelaxedOrder  :1;
    USHORT MaxPayloadSize  :3;
    USHORT ExtendedTagEnable  :1;
    USHORT PhantomFunctionsEnable  :1;
    USHORT AuxPowerEnable  :1;
    USHORT NoSnoopEnable  :1;
    USHORT MaxReadRequestSize  :3;
    USHORT BridgeConfigRetryEnable  :1;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_DEVICE_CONTROL_REGISTER, *PPCI_EXPRESS_DEVICE_CONTROL_REGISTER;