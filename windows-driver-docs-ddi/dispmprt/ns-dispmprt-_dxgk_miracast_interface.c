typedef struct _DXGK_MIRACAST_INTERFACE {
  USHORT                             Size;
  USHORT                             Version;
  PVOID                              Context;
  PINTERFACE_REFERENCE               InterfaceReference;
  PINTERFACE_DEREFERENCE             InterfaceDereference;
  DXGKDDI_MIRACAST_QUERY_CAPS        DxgkDdiMiracastQueryCaps;
  DXGKDDI_MIRACAST_CREATE_CONTEXT    DxgkDdiMiracastCreateContext;
  DXGKDDI_MIRACAST_HANDLE_IO_CONTROL DxgkDdiMiracastIoControl;
  DXGKDDI_MIRACAST_DESTROY_CONTEXT   DxgkDdiMiracastDestroyContext;
} DXGK_MIRACAST_DISPLAY_INTERFACE, *PDXGK_MIRACAST_DISPLAY_INTERFACE;