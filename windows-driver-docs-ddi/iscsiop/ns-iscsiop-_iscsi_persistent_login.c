typedef struct _ISCSI_Persistent_Login {
  WCHAR               TargetName[223 + 1];
  ULONGLONG           SecurityFlags;
  ULONG               InitiatorPortNumber;
  ULONG               UsernameSize;
  BOOLEAN             IsInformationalSession;
  USHORT              UniqueIdForISID;
  ISCSI_TargetPortal  TargetPortal;
  ISCSI_LoginOptions  LoginOptions;
  ISCSI_TargetMapping TargetMapping;
  UCHAR               Username[1];
} ISCSI_Persistent_Login, *PISCSI_Persistent_Login;