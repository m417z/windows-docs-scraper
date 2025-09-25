typedef struct _KSAUDIO_PACKETSIZE_CONSTRAINTS {
  ULONG                                        MinPacketPeriodInHns;
  ULONG                                        PacketSizeFileAlignment;
  ULONG                                        Reserved;
  ULONG                                        NumProcessingModeConstraints;
  KSAUDIO_PACKETSIZE_PROCESSINGMODE_CONSTRAINT ProcessingModeConstraints[ANYSIZE_ARRAY];
} KSAUDIO_PACKETSIZE_CONSTRAINTS;