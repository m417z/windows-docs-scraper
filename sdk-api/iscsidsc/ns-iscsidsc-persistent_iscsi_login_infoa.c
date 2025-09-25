typedef struct {
  CHAR                   TargetName[MAX_ISCSI_NAME_LEN + 1];
  BOOLEAN                IsInformationalSession;
  CHAR                   InitiatorInstance[MAX_ISCSI_HBANAME_LEN];
  ULONG                  InitiatorPortNumber;
  ISCSI_TARGET_PORTALA   TargetPortal;
  ISCSI_SECURITY_FLAGS   SecurityFlags;
  PISCSI_TARGET_MAPPINGA Mappings;
  ISCSI_LOGIN_OPTIONS    LoginOptions;
} PERSISTENT_ISCSI_LOGIN_INFOA, *PPERSISTENT_ISCSI_LOGIN_INFOA;