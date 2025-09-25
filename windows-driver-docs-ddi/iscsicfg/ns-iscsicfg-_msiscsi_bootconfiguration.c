typedef struct _MSiSCSI_BootConfiguration {
  ULONGLONG          LUN;
  ULONGLONG          SecurityFlags;
  ULONG              UsernameSize;
  ULONG              PasswordSize;
  BOOLEAN            DiscoverBootDevice;
  WCHAR              InitiatorNode[223 + 1];
  WCHAR              TargetName[223 + 1];
  ISCSI_TargetPortal TargetPortal;
  ISCSI_LoginOptions LoginOptions;
  UCHAR              Username[1];
} MSiSCSI_BootConfiguration, *PMSiSCSI_BootConfiguration;