typedef struct _DXGKDDI_FLEXIOV_DEVICE_INTERFACE {
  IN USHORT                       Size;
  IN USHORT                       Version;
  OUT PVOID                       Context;
  OUT PINTERFACE_REFERENCE        InterfaceReference;
  OUT PINTERFACE_DEREFERENCE      InterfaceDereference;
  OUT PDXGKDDI_GETBACKINGRESOURCE DxgkDdiGetBackingResource;
  OUT PDXGKDDI_GETMMIORANGECOUNT  DxgkDdiGetMmioRangeCount;
  OUT PDXGKDDI_GETMMIORANGES      DxgkDdiGetMmioRanges;
} DXGKDDI_FLEXIOV_DEVICE_INTERFACE, *PDXGKDDI_FLEXIOV_DEVICE_INTERFACE;