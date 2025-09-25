typedef struct _DXGKVGPU_ESCAPE_READ_PCI_CONFIG {
  DXGKVGPU_ESCAPE_HEAD Header;
  UINT                 Offset;
  UINT                 Size;
} DXGKVGPU_ESCAPE_READ_PCI_CONFIG;