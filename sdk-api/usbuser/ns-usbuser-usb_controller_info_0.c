typedef struct _USB_CONTROLLER_INFO_0 {
  ULONG                 PciVendorId;
  ULONG                 PciDeviceId;
  ULONG                 PciRevision;
  ULONG                 NumberOfRootPorts;
  USB_CONTROLLER_FLAVOR ControllerFlavor;
  ULONG                 HcFeatureFlags;
} USB_CONTROLLER_INFO_0, *PUSB_CONTROLLER_INFO_0;