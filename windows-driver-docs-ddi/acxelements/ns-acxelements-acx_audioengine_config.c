typedef struct _ACX_AUDIOENGINE_CONFIG {
  ULONG                      Size;
  ULONG                      Id;
  const GUID                 *Name;
  ULONG                      Flags;
  ACXPIN                     HostPin;
  ACXPIN                     OffloadPin;
  ACXPIN                     LoopbackPin;
  ACXVOLUME                  VolumeElement;
  ACXMUTE                    MuteElement;
  ACXPEAKMETER               PeakMeterElement;
  PACX_AUDIOENGINE_CALLBACKS Callbacks;
} ACX_AUDIOENGINE_CONFIG, *PACX_AUDIOENGINE_CONFIG;