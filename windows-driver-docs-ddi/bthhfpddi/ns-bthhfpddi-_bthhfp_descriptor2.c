typedef struct _BTHHFP_DESCRIPTOR2 {
  GUID           InputPinCategory;
  GUID           OutputPinCategory;
  GUID           ContainerId;
  BOOL           SupportsVolume;
  ULONG          VolumePropertyValuesSize;
  UNICODE_STRING FriendlyName;
  BOOL           SupportsNREC;
} BTHHFP_DESCRIPTOR2, *PBTHHFP_DESCRIPTOR2;