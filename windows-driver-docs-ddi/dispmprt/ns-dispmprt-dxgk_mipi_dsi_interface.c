typedef struct _DXGK_MIPI_DSI_INTERFACE {
  [in]  IN USHORT                    Size;
  [in]  IN USHORT                    Version;
  [in]  OUT PVOID                    Context;
  [out] OUT PINTERFACE_REFERENCE     InterfaceReference;
  [out] OUT PINTERFACE_DEREFERENCE   InterfaceDereference;
  [out] OUT PDXGKDDI_DSICAPS         DxgkDdiDsiCaps;
  [out] OUT PDXGKDDI_DSITRANSMISSION DxgkDdiDsiTransmission;
  [out] OUT PDXGKDDI_DSIRESET        DxgkDdiDsiReset;
} DXGK_MIPI_DSI_INTERFACE, *PDXGK_MIPI_DSI_INTERFACE;