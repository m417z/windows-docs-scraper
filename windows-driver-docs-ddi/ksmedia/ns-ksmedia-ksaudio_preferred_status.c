typedef struct {
  BOOL                             Enable;
  KSPROPERTY_SYSAUDIO_DEFAULT_TYPE DeviceType;
  ULONG                            Flags;
  ULONG                            Reserved;
} KSAUDIO_PREFERRED_STATUS, *PKSAUDIO_PREFERRED_STATUS;