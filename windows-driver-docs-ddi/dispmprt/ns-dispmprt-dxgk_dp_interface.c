typedef struct _DXGK_DP_INTERFACE {
  IN USHORT                        Size;
  IN USHORT                        Version;
  OUT PVOID                        Context;
  OUT PINTERFACE_REFERENCE         InterfaceReference;
  OUT PINTERFACE_DEREFERENCE       InterfaceDereference;
  OUT PDXGKDDI_QUERYDPCAPS         DxgkDdiQueryDPCaps;
  OUT PDXGKDDI_GETDPADDRESS        DxgkDdiGetDPAddress;
  OUT PDXGKDDI_DPAUXIOTRANSMISSION DxgkDdiDPAuxIoTransmission;
  OUT PDXGKDDI_DPI2CIOTRANSMISSION DxgkDdiDPI2CIoTransmission;
  OUT PDXGKDDI_DPSBMTRANSMISSION   DxgkDdiDPSBMTransmission;
} DXGK_DP_INTERFACE, *PDXGK_DP_INTERFACE;