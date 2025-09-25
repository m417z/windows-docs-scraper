typedef struct _HBAFC3MgmtInfo {
  ULONGLONG UniqueAdapterId;
  UCHAR     wwn[8];
  ULONG     unittype;
  ULONG     PortId;
  ULONG     NumberOfAttachedNodes;
  USHORT    IPVersion;
  USHORT    UDPPort;
  UCHAR     IPAddress[16];
  USHORT    reserved;
  USHORT    TopologyDiscoveryFlags;
  ULONG     reserved1;
} HBAFC3MgmtInfo, *PHBAFC3MgmtInfo;