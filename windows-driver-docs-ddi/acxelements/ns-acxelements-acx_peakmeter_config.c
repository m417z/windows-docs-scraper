typedef struct _ACX_PEAKMETER_CONFIG {
  ULONG                    Size;
  ULONG                    Id;
  const GUID               *Name;
  ULONG                    Flags;
  ULONG                    ChannelsCount;
  LONG                     Maximum;
  LONG                     Minimum;
  ULONG                    SteppingDelta;
  PACX_PEAKMETER_CALLBACKS Callbacks;
} ACX_PEAKMETER_CONFIG, *PACX_PEAKMETER_CONFIG;