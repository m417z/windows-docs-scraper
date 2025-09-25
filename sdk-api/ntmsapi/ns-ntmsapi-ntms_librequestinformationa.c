typedef struct _NTMS_LIBREQUESTINFORMATIONA {
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
  CHAR       szApplication[NTMS_APPLICATIONNAME_LENGTH];
  CHAR       szUser[NTMS_USERNAME_LENGTH];
  CHAR       szComputer[NTMS_COMPUTERNAME_LENGTH];
  DWORD      dwErrorCode;
  NTMS_GUID  WorkItemId;
  DWORD      dwPriority;
} NTMS_LIBREQUESTINFORMATIONA;