typedef struct _DXGK_DISPLAY_INFORMATION {
  UINT                           Width;
  UINT                           Height;
  UINT                           Pitch;
  D3DDDIFORMAT                   ColorFormat;
  PHYSICAL_ADDRESS               PhysicAddress;
  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId;
  ULONG                          AcpiId;
} DXGK_DISPLAY_INFORMATION, *PDXGK_DISPLAY_INFORMATION;