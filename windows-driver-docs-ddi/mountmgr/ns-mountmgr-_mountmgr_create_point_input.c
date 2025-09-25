typedef struct _MOUNTMGR_CREATE_POINT_INPUT {
  USHORT SymbolicLinkNameOffset;
  USHORT SymbolicLinkNameLength;
  USHORT DeviceNameOffset;
  USHORT DeviceNameLength;
} MOUNTMGR_CREATE_POINT_INPUT, *PMOUNTMGR_CREATE_POINT_INPUT;