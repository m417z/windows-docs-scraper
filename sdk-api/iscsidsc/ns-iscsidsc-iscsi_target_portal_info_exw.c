typedef struct {
  WCHAR                InitiatorName[MAX_ISCSI_HBANAME_LEN];
  ULONG                InitiatorPortNumber;
  WCHAR                SymbolicName[MAX_ISCSI_PORTAL_NAME_LEN];
  WCHAR                Address[MAX_ISCSI_PORTAL_ADDRESS_LEN];
  USHORT               Socket;
  ISCSI_SECURITY_FLAGS SecurityFlags;
  ISCSI_LOGIN_OPTIONS  LoginOptions;
} ISCSI_TARGET_PORTAL_INFO_EXW, *PISCSI_TARGET_PORTAL_INFO_EXW;