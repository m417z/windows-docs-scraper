typedef struct _ISCSI_ConnectionStaticInfo {
  ULONGLONG        UniqueConnectionId;
  USHORT           CID;
  UCHAR            State;
  UCHAR            Protocol;
  UCHAR            HeaderIntegrity;
  UCHAR            DataIntegrity;
  USHORT           Reserved;
  ULONG            MaxRecvDataSegmentLength;
  ULONG            AuthType;
  ISCSI_IP_Address LocalAddr;
  ULONG            LocalPort;
  ISCSI_IP_Address RemoteAddr;
  ULONG            RemotePort;
  ULONGLONG        EstimatedThroughput;
  ULONG            MaxDatagramSize;
} ISCSI_ConnectionStaticInfo, *PISCSI_ConnectionStaticInfo;