typedef struct _DBGKD_GET_VERSION64 {
  USHORT  MajorVersion;
  USHORT  MinorVersion;
  UCHAR   ProtocolVersion;
  UCHAR   KdSecondaryVersion;
  USHORT  Flags;
  USHORT  MachineType;
  UCHAR   MaxPacketType;
  UCHAR   MaxStateChange;
  UCHAR   MaxManipulate;
  UCHAR   Simulation;
  USHORT  Unused[1];
  ULONG64 KernBase;
  ULONG64 PsLoadedModuleList;
  ULONG64 DebuggerDataList;
} DBGKD_GET_VERSION64, *PDBGKD_GET_VERSION64;