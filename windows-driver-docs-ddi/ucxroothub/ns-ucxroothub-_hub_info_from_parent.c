typedef struct _HUB_INFO_FROM_PARENT {
  PDEVICE_OBJECT                              IoTarget;
  USB_DEVICE_DESCRIPTOR                       DeviceDescriptor;
  USHORT                                      U1ExitLatency;
  USHORT                                      U2ExitLatency;
  USHORT                                      ExitLatencyOfSlowestLinkForU1;
  UCHAR                                       DepthOfSlowestLinkForU1;
  USHORT                                      ExitLatencyOfSlowestLinkForU2;
  UCHAR                                       DepthOfSlowestLinkForU2;
  USHORT                                      HostInitiatedU1ExitLatency;
  USHORT                                      HostInitiatedU2ExitLatency;
  UCHAR                                       TotalHubDepth;
  USHORT                                      TotalTPPropogationDelay;
  PARENT_HUB_FLAGS                            HubFlags;
  PUSB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED SublinkSpeedAttr;
  ULONG                                       SublinkSpeedAttrCount;
} HUB_INFO_FROM_PARENT, *PHUB_INFO_FROM_PARENT;