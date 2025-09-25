typedef struct _MOUNTMGR_MOUNT_POINT {
  ULONG  SymbolicLinkNameOffset;
  USHORT SymbolicLinkNameLength;
  USHORT Reserved1;
  ULONG  UniqueIdOffset;
  USHORT UniqueIdLength;
  USHORT Reserved2;
  ULONG  DeviceNameOffset;
  USHORT DeviceNameLength;
  USHORT Reserved3;
} MOUNTMGR_MOUNT_POINT, *PMOUNTMGR_MOUNT_POINT;