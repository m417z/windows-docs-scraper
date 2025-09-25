typedef struct {
  ISCSI_UNIQUE_SESSION_ID SessionId;
  PWCHAR                  InitiatorName;
  PWCHAR                  TargetNodeName;
  PWCHAR                  TargetName;
  UCHAR                   ISID[6];
  UCHAR                   TSID[2];
  ULONG                   ConnectionCount;
  PISCSI_CONNECTION_INFOW Connections;
} ISCSI_SESSION_INFOW, *PISCSI_SESSION_INFOW;