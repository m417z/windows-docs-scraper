typedef struct _ACPI_PLD_SPATIAL_BUFFER {
  UINT32 Revision : 5;
  UINT32 RollRotation : 9;
  UINT32 PitchRotation : 9;
  UINT32 YawRotation : 9;
  UINT32 Width : 16;
  UINT32 Height : 16;
  UINT32 Length : 16;
  UINT32 HorizontalOffset : 16;
  UINT32 VerticalOffset : 16;
  UINT32 DepthOffset : 16;
} ACPI_PLD_SPATIAL_BUFFER, *PACPI_PLD_SPATIAL_BUFFER;