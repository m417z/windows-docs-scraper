typedef struct _ACX_STREAMAUDIOENGINE_CONFIG {
  ULONG                            Size;
  ULONG                            Id;
  const GUID                       *Name;
  ULONG                            Flags;
  ACXVOLUME                        VolumeElement;
  ACXMUTE                          MuteElement;
  ACXPEAKMETER                     PeakMeterElement;
  PACX_STREAMAUDIOENGINE_CALLBACKS Callbacks;
} ACX_STREAMAUDIOENGINE_CONFIG, *PACX_STREAMAUDIOENGINE_CONFIG;