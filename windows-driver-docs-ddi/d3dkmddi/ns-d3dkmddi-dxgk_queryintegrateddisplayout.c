typedef struct _DXGK_QUERYINTEGRATEDDISPLAYOUT {
  DXGK_INTEGRATEDDISPLAYFLAGS       Flags;
  D3DKMDT_VIDEO_SIGNAL_INFO         NativeTiming;
  DXGK_MONITORLINKINFO_CAPABILITIES LinkCapabilities;
  DXGK_COLORIMETRY                  Colorimetry;
  DXGK_DISPLAY_TECHNOLOGY           DisplayTechnology;
  DXGK_DISPLAY_USAGE                IntendedUsage;
  BYTE                              Instance;
  DXGK_DISPLAY_DESCRIPTOR_TYPE      DescriptorType;
  BYTE                              Descriptor[1];
} DXGK_QUERYINTEGRATEDDISPLAYOUT, *PDXGK_QUERYINTEGRATEDDISPLAYOUT;