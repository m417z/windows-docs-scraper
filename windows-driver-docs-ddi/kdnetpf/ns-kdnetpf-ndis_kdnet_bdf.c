typedef struct _NDIS_KDNET_BDF {
  ULONG SegmentNumber;
  ULONG BusNumber;
  ULONG DeviceNumber;
  ULONG FunctionNumber;
  ULONG Reserved;
} NDIS_KDNET_BDF, *PNDIS_KDNET_PCI_BDF;