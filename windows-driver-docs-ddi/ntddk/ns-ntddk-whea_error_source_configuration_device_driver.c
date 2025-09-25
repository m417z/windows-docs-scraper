typedef struct _WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER {
  ULONG                                        Version;
  GUID                                         SourceGuid;
  USHORT                                       LogTag;
  UCHAR                                        Reserved[6];
  WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER   Initialize;
  WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER Uninitialize;
  ULONG                                        MaxSectionDataLength;
  ULONG                                        MaxSectionsPerReport;
  GUID                                         CreatorId;
  GUID                                         PartitionId;
} WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER, *PWHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER;