typedef struct {
  DS3DVECTOR Position;
  DS3DVECTOR Velocity;
  ULONG      InsideConeAngle;
  ULONG      OutsideConeAngle;
  DS3DVECTOR ConeOrientation;
  LONG       ConeOutsideVolume;
  FLOAT      MinDistance;
  FLOAT      MaxDistance;
  ULONG      Mode;
} KSDS3D_BUFFER_ALL, *PKSDS3D_BUFFER_ALL;