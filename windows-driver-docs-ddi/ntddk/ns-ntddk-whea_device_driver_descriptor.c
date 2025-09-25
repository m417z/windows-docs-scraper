typedef struct _WHEA_DEVICE_DRIVER_DESCRIPTOR {
  USHORT                             Type;
  BOOLEAN                            Enabled;
  UCHAR                              Reserved;
  GUID                               SourceGuid;
  USHORT                             LogTag;
  USHORT                             Reserved2;
  ULONG                              PacketLength;
  ULONG                              PacketCount;
  PUCHAR                             PacketBuffer;
  WHEA_ERROR_SOURCE_CONFIGURATION_DD Config;
  GUID                               CreatorId;
  GUID                               PartitionId;
  ULONG                              MaxSectionDataLength;
  ULONG                              MaxSectionsPerRecord;
  PUCHAR                             PacketStateBuffer;
  LONG                               OpenHandles;
} WHEA_DEVICE_DRIVER_DESCRIPTOR, *PWHEA_DEVICE_DRIVER_DESCRIPTOR;