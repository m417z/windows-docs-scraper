typedef struct {
  KSPROPERTY Property;
  ULONG      StreamIndex;
  LONG       DefaultKeyFrameRate;
  LONG       DefaultPFrameRate;
  LONG       DefaultQuality;
  LONG       NumberOfQualitySettings;
  LONG       Capabilities;
} KSPROPERTY_VIDEOCOMPRESSION_GETINFO_S, *PKSPROPERTY_VIDEOCOMPRESSION_GETINFO_S;