typedef struct {
  WCHAR                   InitiatorName[MAX_ISCSI_HBANAME_LEN];
  WCHAR                   TargetName[MAX_ISCSI_NAME_LEN + 1];
  WCHAR                   OSDeviceName[MAX_PATH];
  ISCSI_UNIQUE_SESSION_ID SessionId;
  ULONG                   OSBusNumber;
  ULONG                   OSTargetNumber;
  ULONG                   LUNCount;
  PSCSI_LUN_LIST          LUNList;
} ISCSI_TARGET_MAPPINGW, *PISCSI_TARGET_MAPPINGW;