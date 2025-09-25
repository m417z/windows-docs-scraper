typedef struct _KSPROPERTY_SPHLI {
  USHORT    HLISS;
  USHORT    Reserved;
  ULONG     StartPTM;
  ULONG     EndPTM;
  USHORT    StartX;
  USHORT    StartY;
  USHORT    StopX;
  USHORT    StopY;
  KS_COLCON ColCon;
} KSPROPERTY_SPHLI, *PKSPROPERTY_SPHLI;