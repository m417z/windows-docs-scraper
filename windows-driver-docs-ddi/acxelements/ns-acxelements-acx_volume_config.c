typedef struct _ACX_VOLUME_CONFIG {
  ULONG                 Size;
  ULONG                 Id;
  const GUID            *Name;
  ULONG                 Flags;
  ULONG                 ChannelsCount;
  LONG                  Maximum;
  LONG                  Minimum;
  ULONG                 SteppingDelta;
  PACX_VOLUME_CALLBACKS Callbacks;
} ACX_VOLUME_CONFIG, *PACX_VOLUME_CONFIG;