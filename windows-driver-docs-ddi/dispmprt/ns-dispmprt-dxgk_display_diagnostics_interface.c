typedef struct _DXGK_DISPLAY_DIAGNOSTICS_INTERFACE {
  [in]  IN USHORT                               Size;
  [in]  IN USHORT                               Version;
  [out] OUT PVOID                               Context;
  [out] OUT PINTERFACE_REFERENCE                InterfaceReference;
  [out] OUT PINTERFACE_DEREFERENCE              InterfaceDereference;
  [out] OUT DXGKDDI_GETDISPLAYSTATENONINTRUSIVE DxgkDdiGetDisplayStateNonIntrusive;
  [out] OUT DXGKDDI_GETDISPLAYSTATEINTRUSIVE    DxgkDdiGetDisplayStateIntrusive;
} DXGK_DISPLAY_DIAGNOSTICS_INTERFACE, *PDXGK_DISPLAY_DIAGNOSTICS_INTERFACE;