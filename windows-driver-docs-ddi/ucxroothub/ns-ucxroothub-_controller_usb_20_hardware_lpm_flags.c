typedef union _CONTROLLER_USB_20_HARDWARE_LPM_FLAGS {
  UCHAR  AsUchar;
  struct {
    UCHAR L1CapabilitySupported : 1;
    UCHAR BeslLpmCapabilitySupported : 1;
  } Flags;
  struct {
    UCHAR L1CapabilitySupported : 1;
    UCHAR BeslLpmCapabilitySupported : 1;
  };
} CONTROLLER_USB_20_HARDWARE_LPM_FLAGS, *PCONTROLLER_USB_20_HARDWARE_LPM_FLAGS;