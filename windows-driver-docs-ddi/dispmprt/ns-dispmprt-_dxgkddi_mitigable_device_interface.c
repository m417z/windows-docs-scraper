typedef struct _DXGKDDI_MITIGABLE_DEVICE_INTERFACE {
  IN USHORT                             Size;
  IN USHORT                             Version;
  OUT PVOID                             Context;
  OUT PINTERFACE_REFERENCE              InterfaceReference;
  OUT PINTERFACE_DEREFERENCE            InterfaceDereference;
  OUT PDXGKDDI_QUERYMITIGATEDRANGECOUNT DxgkDdiQueryMitigatedRangeCount;
  OUT PDXGKDDI_QUERYMITIGATEDRANGES     DxgkDdiQueryMitigatedRanges;
} DXGKDDI_MITIGABLE_DEVICE_INTERFACE, *PDXGKDDI_MITIGABLE_DEVICE_INTERFACE;