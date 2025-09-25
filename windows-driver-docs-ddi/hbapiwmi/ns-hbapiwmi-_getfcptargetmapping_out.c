typedef struct _GetFcpTargetMapping_OUT {
  ULONG           HBAStatus;
  ULONG           TotalEntryCount;
  ULONG           OutEntryCount;
  HBAFCPScsiEntry Entry[1];
} GetFcpTargetMapping_OUT, *PGetFcpTargetMapping_OUT;