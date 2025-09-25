typedef struct _ISCSI_TargetMapping {
  ULONG         OSBus;
  ULONG         OSTarget;
  ULONGLONG     UniqueSessionId;
  ULONG         LUNCount;
  WCHAR         TargetName[223 + 1];
  BOOLEAN       FromPersistentLogin;
  ULONGLONG     Reserved;
  ISCSI_LUNList LUNList[1];
} ISCSI_TargetMapping, *PISCSI_TargetMapping;