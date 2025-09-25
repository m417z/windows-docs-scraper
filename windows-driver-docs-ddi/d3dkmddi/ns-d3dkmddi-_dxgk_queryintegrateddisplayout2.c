typedef struct _DXGK_QUERYINTEGRATEDDISPLAYOUT2 {
  [out] DXGK_INTEGRATEDDISPLAYFLAGS        Flags;
  [out] D3DKMDT_VIDEO_SIGNAL_INFO          NativeTiming;
  [out] DXGK_MONITORLINKINFO_CAPABILITIES  LinkCapabilities;
  [out] DXGK_COLORIMETRY                   Colorimetry;
  [out] DXGK_DISPLAY_TECHNOLOGY            DisplayTechnology;
  [out] DXGK_DISPLAY_USAGE                 IntendedUsage;
  [out] BYTE                               Instance;
  [out] DXGK_DISPLAY_DESCRIPTOR_TYPE       DescriptorType;
  [out] D3DKMDT_WIRE_FORMAT_AND_PREFERENCE DitheringSupport;
} DXGK_QUERYINTEGRATEDDISPLAYOUT2, *PDXGK_QUERYINTEGRATEDDISPLAYOUT2;