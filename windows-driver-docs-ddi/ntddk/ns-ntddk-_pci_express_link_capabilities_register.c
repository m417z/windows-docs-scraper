typedef union _PCI_EXPRESS_LINK_CAPABILITIES_REGISTER {
  struct {
    ULONG MaximumLinkSpeed  :4;
    ULONG MaximumLinkWidth  :6;
    ULONG ActiveStatePMSupport  :2;
    ULONG L0sExitLatency  :3;
    ULONG L1ExitLatency  :3;
    ULONG ClockPowerManagement  :1;
    ULONG SurpriseDownErrorReportingCapable  :1;
    ULONG DataLinkLayerActiveReportingCapable  :1;
    ULONG LinkBandwidthNotificationCapability:1;
    ULONG AspmOptionalityCompliance:1;
    ULONG Rsvd  :1;
    ULONG PortNumber  :8;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_LINK_CAPABILITIES_REGISTER, *PPCI_EXPRESS_LINK_CAPABILITIES_REGISTER;