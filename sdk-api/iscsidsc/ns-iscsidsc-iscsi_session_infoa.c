typedef struct {
  ISCSI_UNIQUE_SESSION_ID SessionId;
  PCHAR                   InitiatorName;
  PCHAR                   TargetNodeName;
  PCHAR                   TargetName;
  UCHAR                   ISID[6];
  UCHAR                   TSID[2];
  ULONG                   ConnectionCount;
  PISCSI_CONNECTION_INFOA Connections;
} ISCSI_SESSION_INFOA, *PISCSI_SESSION_INFOA;