typedef struct _LoginToTarget_IN {
  ULONG               PortNumber;
  ISCSI_LoginOptions  LoginOptions;
  ULONG               SessionType;
  ULONGLONG           SecurityFlags;
  ISCSI_TargetPortal  TargetPortal;
  ULONG               UsernameSize;
  ULONG               PasswordSize;
  ULONG               KeySize;
  USHORT              UniqueIdForISID;
  BOOLEAN             PersistentLogin;
  WCHAR               InitiatorNode[223 + 1];
  WCHAR               InitiatorAlias[255 + 1];
  WCHAR               TargetName[223 + 1];
  ISCSI_TargetMapping Mappings;
  UCHAR               Key[1];
} LoginToTarget_IN, *PLoginToTarget_IN;