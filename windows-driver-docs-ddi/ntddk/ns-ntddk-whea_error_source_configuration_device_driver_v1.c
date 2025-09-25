typedef struct _WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER_V1 {
  ULONG                                        Version;
  GUID                                         SourceGuid;
  USHORT                                       LogTag;
  UCHAR                                        Reserved[6];
  WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER   Initialize;
  WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER Uninitialize;
} WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER_V1, *PWHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER_V1;