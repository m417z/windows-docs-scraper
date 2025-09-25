typedef struct _SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR2 {
  ULONG                               CbSize;
  GUID                                ContainerId;
  GUID                                Category;
  KSPIN_DATAFLOW                      Direction;
  SIDEBANDAUDIO_ENDPOINT_CAPABILITIES Capabilities;
  UNICODE_STRING                      FriendlyName;
  ULONG                               VolumePropertyValuesSize;
  ULONG                               SidetoneVolumePropertyValueSize;
  ULONG                               MutePropertyValuesSize;
  ULONG                               FilterInterfacePropertyCount;
  DEVPROPERTY                         *FilterInterfaceProperties;
} SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR2, *PSIDEBANDAUDIO_ENDPOINT_DESCRIPTOR2;