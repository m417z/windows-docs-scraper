typedef struct _DXGKARG_DESCRIBEALLOCATION {
  [in]  HANDLE                       hAllocation;
  [out] UINT                         Width;
  [out] UINT                         Height;
  [out] D3DDDIFORMAT                 Format;
  [out] D3DDDI_MULTISAMPLINGMETHOD   MultisampleMethod;
  [out] D3DDDI_RATIONAL              RefreshRate;
  [out] UINT                         PrivateDriverFormatAttribute;
  [out] DXGK_DESCRIBEALLOCATIONFLAGS Flags;
  [out] D3DDDI_ROTATION              Rotation;
} DXGKARG_DESCRIBEALLOCATION;