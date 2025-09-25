typedef struct _RemovePersistentLogin_IN {
  ULONG              PortNumber;
  WCHAR              TargetName[223 + 1];
  ISCSI_TargetPortal TargetPortal;
} RemovePersistentLogin_IN, *PRemovePersistentLogin_IN;