typedef struct _VDS_DRIVE_PROP {
  VDS_OBJECT_ID    id;
  ULONGLONG        ullSize;
  LPWSTR           pwszFriendlyName;
  LPWSTR           pwszIdentification;
  ULONG            ulFlags;
  VDS_DRIVE_STATUS status;
  VDS_HEALTH       health;
  SHORT            sInternalBusNumber;
  SHORT            sSlotNumber;
} VDS_DRIVE_PROP, *PVDS_DRIVE_PROP;