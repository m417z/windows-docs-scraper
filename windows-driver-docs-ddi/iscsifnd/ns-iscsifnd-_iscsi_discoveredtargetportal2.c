typedef struct _ISCSI_DiscoveredTargetPortal2 {
  USHORT           Socket;
  ISCSI_IP_Address Address;
  ULONG            SecurityBitmap;
  ULONG            KeySize;
  UCHAR            Key[1];
} ISCSI_DiscoveredTargetPortal2, *PISCSI_DiscoveredTargetPortal2;