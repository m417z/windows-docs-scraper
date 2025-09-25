typedef struct {
  KSPROPERTY Property;
  ULONG      StreamIndex;
  ULONG      RangeIndex;
  SIZE       Dimensions;
  LONGLONG   CurrentActualFrameRate;
  LONGLONG   CurrentMaxAvailableFrameRate;
} KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE_S, *PKSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE_S;