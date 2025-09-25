typedef struct _IDE_TRANSFER_MODE_PARAMETERS {
  UCHAR           ChannelNumber;
  IDE_DEVICE_TYPE DeviceType[MAX_IDE_DEVICE];
  BOOLEAN         IoReadySupported[MAX_IDE_DEVICE];
  ULONG           DeviceTransferModeSupported[MAX_IDE_DEVICE];
  ULONG           DeviceTransferModeCurrent[MAX_IDE_DEVICE];
  ULONG           DeviceTransferModeSelected[MAX_IDE_DEVICE];
} IDE_TRANSFER_MODE_PARAMETERS, *PIDE_TRANSFER_MODE_PARAMETERS;