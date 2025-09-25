typedef struct _NTMS_DRIVEINFORMATIONW {
  DWORD      Number;
  DWORD      State;
  NTMS_GUID  DriveType;
  WCHAR      szDeviceName[NTMS_DEVICENAME_LENGTH];
  WCHAR      szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
  WCHAR      szRevision[NTMS_REVISION_LENGTH];
  WORD       ScsiPort;
  WORD       ScsiBus;
  WORD       ScsiTarget;
  WORD       ScsiLun;
  DWORD      dwMountCount;
  SYSTEMTIME LastCleanedTs;
  NTMS_GUID  SavedPartitionId;
  NTMS_GUID  Library;
  GUID       Reserved;
  DWORD      dwDeferDismountDelay;
} NTMS_DRIVEINFORMATIONW;