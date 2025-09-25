typedef struct {
  CHAR                    InitiatorName[MAX_ISCSI_HBANAME_LEN];
  CHAR                    TargetName[MAX_ISCSI_NAME_LEN + 1];
  CHAR                    OSDeviceName[MAX_PATH];
  ISCSI_UNIQUE_SESSION_ID SessionId;
  ULONG                   OSBusNumber;
  ULONG                   OSTargetNumber;
  ULONG                   LUNCount;
  PSCSI_LUN_LIST          LUNList;
} ISCSI_TARGET_MAPPINGA, *PISCSI_TARGET_MAPPINGA;