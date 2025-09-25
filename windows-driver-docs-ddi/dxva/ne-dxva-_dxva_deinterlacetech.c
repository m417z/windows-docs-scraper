typedef enum _DXVA_DeinterlaceTech {
  DXVA_DeinterlaceTech_Unknown,
  DXVA_DeinterlaceTech_BOBLineReplicate,
  DXVA_DeinterlaceTech_BOBVerticalStretch,
  DXVA_DeinterlaceTech_BOBVerticalStretch4Tap,
  DXVA_DeinterlaceTech_MedianFiltering,
  DXVA_DeinterlaceTech_EdgeFiltering,
  DXVA_DeinterlaceTech_FieldAdaptive,
  DXVA_DeinterlaceTech_PixelAdaptive,
  DXVA_DeinterlaceTech_MotionVectorSteered
} DXVA_DeinterlaceTech;