typedef enum WICPngFilterOption {
  WICPngFilterUnspecified = 0,
  WICPngFilterNone = 0x1,
  WICPngFilterSub = 0x2,
  WICPngFilterUp = 0x3,
  WICPngFilterAverage = 0x4,
  WICPngFilterPaeth = 0x5,
  WICPngFilterAdaptive = 0x6,
  WICPNGFILTEROPTION_FORCE_DWORD = 0x7fffffff
} ;