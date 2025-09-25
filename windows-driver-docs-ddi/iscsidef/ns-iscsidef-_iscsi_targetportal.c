typedef struct _ISCSI_TargetPortal {
  ISCSI_IP_Address Address;
  ULONG            Reserved;
  USHORT           Socket;
} ISCSI_TargetPortal, *PISCSI_TargetPortal;