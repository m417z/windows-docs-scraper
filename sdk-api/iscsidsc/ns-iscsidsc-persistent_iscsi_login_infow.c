typedef struct {
  WCHAR                  TargetName[MAX_ISCSI_NAME_LEN + 1];
  BOOLEAN                IsInformationalSession;
  WCHAR                  InitiatorInstance[MAX_ISCSI_HBANAME_LEN];
  ULONG                  InitiatorPortNumber;
  ISCSI_TARGET_PORTALW   TargetPortal;
  ISCSI_SECURITY_FLAGS   SecurityFlags;
  PISCSI_TARGET_MAPPINGW Mappings;
  ISCSI_LOGIN_OPTIONS    LoginOptions;
} PERSISTENT_ISCSI_LOGIN_INFOW, *PPERSISTENT_ISCSI_LOGIN_INFOW;