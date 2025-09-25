typedef struct _BTHHFP_DESCRIPTOR {
  GUID           InputPinCategory;
  GUID           OutputPinCategory;
  GUID           ContainerId;
  BOOL           SupportsVolume;
  ULONG          VolumePropertyValuesSize;
  UNICODE_STRING FriendlyName;
} BTHHFP_DESCRIPTOR, *PBTHHFP_DESCRIPTOR;