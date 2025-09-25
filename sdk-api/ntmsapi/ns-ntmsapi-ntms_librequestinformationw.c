typedef struct _NTMS_LIBREQUESTINFORMATIONW {
  DWORD      OperationCode;
  DWORD      OperationOption;
  DWORD      State;
  NTMS_GUID  PartitionId;
  NTMS_GUID  DriveId;
  NTMS_GUID  PhysMediaId;
  NTMS_GUID  Library;
  NTMS_GUID  SlotId;
  SYSTEMTIME TimeQueued;
  SYSTEMTIME TimeCompleted;
  WCHAR      szApplication[NTMS_APPLICATIONNAME_LENGTH];
  WCHAR      szUser[NTMS_USERNAME_LENGTH];
  WCHAR      szComputer[NTMS_COMPUTERNAME_LENGTH];
  DWORD      dwErrorCode;
  NTMS_GUID  WorkItemId;
  DWORD      dwPriority;
} NTMS_LIBREQUESTINFORMATIONW;