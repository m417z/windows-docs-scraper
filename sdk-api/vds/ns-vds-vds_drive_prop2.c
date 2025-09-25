typedef struct _VDS_DRIVE_PROP2 {
  VDS_OBJECT_ID        id;
  ULONGLONG            ullSize;
  LPWSTR               pwszFriendlyName;
  LPWSTR               pwszIdentification;
  ULONG                ulFlags;
  VDS_DRIVE_STATUS     status;
  VDS_HEALTH           health;
  SHORT                sInternalBusNumber;
  SHORT                sSlotNumber;
  ULONG                ulEnclosureNumber;
  VDS_STORAGE_BUS_TYPE busType;
  ULONG                ulSpindleSpeed;
} VDS_DRIVE_PROP2, *PVDS_DRIVE_PROP2;