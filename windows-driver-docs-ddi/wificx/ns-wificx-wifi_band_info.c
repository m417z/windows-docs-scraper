typedef struct _WIFI_BAND_INFO {
  WDI_BAND_ID               BandID;
  BOOLEAN                   BandState;
  ULONG                     NumValidPhyTypes;
  WDI_PHY_TYPE              *ValidPhyTypeList;
  ULONG                     NumValidChannelTypes;
  WDI_CHANNEL_MAPPING_ENTRY *ValidChannelTypes;
  ULONG                     NumChannelWidths;
  UINT32                    *ChannelWidthList;
} WIFI_BAND_INFO;