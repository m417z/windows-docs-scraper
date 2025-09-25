typedef struct _IDE_CHANNEL_CONFIGURATION {
  USHORT                              Version;
  UCHAR                               ChannelNumber;
  SUPPORTED_ADVANCES                  SupportedAdvances;
  IDE_OPERATION_MODE                  ChannelMode;
  PIDE_MINIPORT_RESOURCES             ChannelResources;
  UCHAR                               NumberOfOverlappedRequests;
  UCHAR                               MaxTargetId;
  BOOLEAN                             SyncWithIsr;
  BOOLEAN                             SupportsWmi;
  PIDE_ADVANCED_CHANNEL_CONFIGURATION AdvancedChannelConfiguration;
} IDE_CHANNEL_CONFIGURATION, *PIDE_CHANNEL_CONFIGURATION;