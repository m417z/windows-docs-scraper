typedef struct _IDE_CONTROLLER_CONFIGURATION {
  USHORT                  Version;
  UCHAR                   NumberOfChannels;
  IDE_OPERATION_MODE      ControllerMode;
  UCHAR                   NumberOfPhysicalBreaks;
  ULONG                   MaximumTransferLength;
  BOOLEAN                 Reserved;
  BOOLEAN                 NativeModeEnabled;
  BOOLEAN                 Dma64BitAddress;
  BOOLEAN                 BusMaster;
  IDE_BUS_TYPE            AtaBusType;
  PIDE_MINIPORT_RESOURCES ControllerResources;
} IDE_CONTROLLER_CONFIGURATION, *PIDE_CONTROLLER_CONFIGURATION;