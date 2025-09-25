typedef enum VMRDeinterlaceTech {
  DeinterlaceTech_Unknown = 0,
  DeinterlaceTech_BOBLineReplicate = 0x1,
  DeinterlaceTech_BOBVerticalStretch = 0x2,
  DeinterlaceTech_MedianFiltering = 0x4,
  DeinterlaceTech_EdgeFiltering = 0x10,
  DeinterlaceTech_FieldAdaptive = 0x20,
  DeinterlaceTech_PixelAdaptive = 0x40,
  DeinterlaceTech_MotionVectorSteered = 0x80
} ;