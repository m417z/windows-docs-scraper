typedef struct {
  KSDATARANGE DataRange;
  GUID        Technology;
  ULONG       Channels;
  ULONG       Notes;
  ULONG       ChannelMask;
} KSDATARANGE_MUSIC, *PKSDATARANGE_MUSIC;