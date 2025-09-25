typedef struct _STOR_DEVICE_CAPABILITIES {
  USHORT Version;
  ULONG  DeviceD1 : 1;
  ULONG  DeviceD2 : 1;
  ULONG  LockSupported : 1;
  ULONG  EjectSupported : 1;
  ULONG  Removable : 1;
  ULONG  DockDevice : 1;
  ULONG  UniqueID : 1;
  ULONG  SilentInstall : 1;
  ULONG  SurpriseRemovalOK : 1;
  ULONG  NoDisplayInUI : 1;
} STOR_DEVICE_CAPABILITIES, *PSTOR_DEVICE_CAPABILITIES;