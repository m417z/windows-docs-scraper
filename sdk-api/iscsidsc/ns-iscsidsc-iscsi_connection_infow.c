typedef struct {
  ISCSI_UNIQUE_CONNECTION_ID ConnectionId;
  PWCHAR                     InitiatorAddress;
  PWCHAR                     TargetAddress;
  USHORT                     InitiatorSocket;
  USHORT                     TargetSocket;
  UCHAR                      CID[2];
} ISCSI_CONNECTION_INFOW, *PISCSI_CONNECTION_INFOW;