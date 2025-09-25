typedef struct {
  KSPROPERTY Property;
  GUID       SourceFormat;
  GUID       TargetFormat;
  LONGLONG   Time;
} KSP_TIMEFORMAT, *PKSP_TIMEFORMAT;