typedef struct _MPIO_DSM_Path_V2 {
  ULONGLONG DsmPathId;
  ULONGLONG Reserved;
  ULONG     PathWeight;
  ULONG     PrimaryPath;
  ULONG     OptimizedPath;
  ULONG     PreferredPath;
  ULONG     FailedPath;
  ULONG     TargetPortGroup_State;
  ULONG     ALUASupport;
  UCHAR     SymmetricLUA;
  UCHAR     TargetPortGroup_Preferred;
  USHORT    TargetPortGroup_Identifier;
  ULONG     TargetPort_Identifier;
  ULONG     Reserved32;
  ULONGLONG Reserved64;
} MPIO_DSM_Path_V2, *PMPIO_DSM_Path_V2;