typedef struct _ACX_MUTE_CONFIG {
  ULONG               Size;
  ULONG               Id;
  const GUID          *Name;
  ULONG               Flags;
  ULONG               ChannelsCount;
  PACX_MUTE_CALLBACKS Callbacks;
} ACX_MUTE_CONFIG, *PACX_MUTE_CONFIG;