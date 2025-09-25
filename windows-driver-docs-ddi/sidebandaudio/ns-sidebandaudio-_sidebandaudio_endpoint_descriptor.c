typedef struct _SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR {
  ULONG                               CbSize;
  GUID                                ContainerId;
  GUID                                Category;
  KSPIN_DATAFLOW                      Direction;
  SIDEBANDAUDIO_ENDPOINT_CAPABILITIES Capabilities;
  UNICODE_STRING                      FriendlyName;
  ULONG                               VolumePropertyValuesSize;
  ULONG                               SidetoneVolumePropertyValueSize;
  ULONG                               MutePropertyValuesSize;
} SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR, *PSIDEBANDAUDIO_ENDPOINT_DESCRIPTOR;