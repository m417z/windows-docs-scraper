typedef struct _SFFDISK_DEVICE_COMMAND_DATA {
  USHORT       HeaderSize;
  USHORT       Flags;
  SFFDISK_DCMD Command;
  USHORT       ProtocolArgumentSize;
  ULONG        DeviceDataBufferSize;
  ULONG_PTR    Information;
  UCHAR        Data[0];
} SFFDISK_DEVICE_COMMAND_DATA, *PSFFDISK_DEVICE_COMMAND_DATA;