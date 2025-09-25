typedef struct _ISCSI_SessionStaticInfo {
  ULONGLONG                  UniqueSessionId;
  WCHAR                      InitiatoriSCSIName[223 + 1];
  WCHAR                      TargetiSCSIName[223 + 1];
  USHORT                     TSID;
  UCHAR                      ISID[6];
  BOOLEAN                    InitialR2t;
  BOOLEAN                    ImmediateData;
  UCHAR                      Type;
  BOOLEAN                    DataSequenceInOrder;
  BOOLEAN                    DataPduInOrder;
  UCHAR                      ErrorRecoveryLevel;
  ULONG                      MaxOutstandingR2t;
  ULONG                      FirstBurstLength;
  ULONG                      MaxBurstLength;
  ULONG                      MaxConnections;
  USHORT                     ConnectionCount;
  ISCSI_ConnectionStaticInfo ConnectionsList[1];
} ISCSI_SessionStaticInfo, *PISCSI_SessionStaticInfo;