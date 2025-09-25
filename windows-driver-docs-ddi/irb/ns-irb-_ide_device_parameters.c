typedef struct _IDE_DEVICE_PARAMETERS {
  USHORT                  Version;
  IDE_DEVICE_TYPE         IdeDeviceType;
  UCHAR                   TargetId;
  UCHAR                   MaximumLun;
  UCHAR                   NumberOfOverlappedRequests;
  UCHAR                   MaxBlockXfer;
  USHORT                  DeviceCharacteristics;
  ATA_ADDRESS_TRANSLATION AddressTranslation;
  union {
    LARGE_INTEGER MaxLba;
    struct {
      USHORT NumCylinders;
      USHORT NumHeads;
      USHORT NumSectorsPerTrack;
      USHORT Reserved;
    } Chs;
  };
  ULONG                   BytesPerLogicalSector;
  ULONG                   BytesPerPhysicalSector;
  ULONG                   BytesOffsetForSectorAlignment;
  ULONG                   TransferModeSupported;
  ULONG                   TransferModeSelected;
} IDE_DEVICE_PARAMETERS, *PIDE_DEVICE_PARAMETERS;