typedef struct {
  EMI_MEASUREMENT_UNIT MeasurementUnit;
  USHORT               ChannelNameSize;
  WCHAR                ChannelName[ANYSIZE_ARRAY];
} EMI_CHANNEL_V2;