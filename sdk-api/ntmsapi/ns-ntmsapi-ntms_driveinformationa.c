typedef struct _NTMS_DRIVEINFORMATIONA {
  DWORD      Number;
  DWORD      State;
  NTMS_GUID  DriveType;
  CHAR       szDeviceName[NTMS_DEVICENAME_LENGTH];
  CHAR       szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
  CHAR       szRevision[NTMS_REVISION_LENGTH];
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
} NTMS_DRIVEINFORMATIONA;