typedef struct {
  ISCSI_UNIQUE_CONNECTION_ID ConnectionId;
  PCHAR                      InitiatorAddress;
  PCHAR                      TargetAddress;
  USHORT                     InitiatorSocket;
  USHORT                     TargetSocket;
  UCHAR                      CID[2];
} ISCSI_CONNECTION_INFOA, *PISCSI_CONNECTION_INFOA;