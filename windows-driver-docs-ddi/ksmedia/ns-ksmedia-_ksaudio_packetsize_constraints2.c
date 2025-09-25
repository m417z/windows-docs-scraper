typedef struct _KSAUDIO_PACKETSIZE_CONSTRAINTS2 {
  ULONG                                        MinPacketPeriodInHns;
  ULONG                                        PacketSizeFileAlignment;
  ULONG                                        MaxPacketSizeInBytes;
  ULONG                                        NumProcessingModeConstraints;
  KSAUDIO_PACKETSIZE_PROCESSINGMODE_CONSTRAINT ProcessingModeConstraints[ANYSIZE_ARRAY];
} KSAUDIO_PACKETSIZE_CONSTRAINTS2;