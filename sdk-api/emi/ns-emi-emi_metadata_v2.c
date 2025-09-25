typedef struct {
  WCHAR          HardwareOEM[EMI_NAME_MAX];
  WCHAR          HardwareModel[EMI_NAME_MAX];
  USHORT         HardwareRevision;
  USHORT         ChannelCount;
  EMI_CHANNEL_V2 Channels[ANYSIZE_ARRAY];
} EMI_METADATA_V2;