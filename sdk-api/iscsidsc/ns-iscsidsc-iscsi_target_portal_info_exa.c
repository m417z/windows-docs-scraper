typedef struct {
  CHAR                 InitiatorName[MAX_ISCSI_HBANAME_LEN];
  ULONG                InitiatorPortNumber;
  CHAR                 SymbolicName[MAX_ISCSI_PORTAL_NAME_LEN];
  CHAR                 Address[MAX_ISCSI_PORTAL_ADDRESS_LEN];
  USHORT               Socket;
  ISCSI_SECURITY_FLAGS SecurityFlags;
  ISCSI_LOGIN_OPTIONS  LoginOptions;
} ISCSI_TARGET_PORTAL_INFO_EXA, *PISCSI_TARGET_PORTAL_INFO_EXA;