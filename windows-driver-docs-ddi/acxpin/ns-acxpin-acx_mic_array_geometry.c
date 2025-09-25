typedef struct _ACX_MIC_ARRAY_GEOMETRY {
  USHORT Version;
  USHORT MicArrayType;
  SHORT  VerticalAngleBegin;
  SHORT  VerticalAngleEnd;
  SHORT  HorizontalAngleBegin;
  SHORT  HorizontalAngleEnd;
  ULONG  FrequencyBandLo;
  ULONG  FrequencyBandHi;
} ACX_MIC_ARRAY_GEOMETRY, *PACX_MIC_ARRAY_GEOMETRY;