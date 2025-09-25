typedef struct HBA_MgmtInfo {
  HBA_WWN    wwn;
  HBA_UINT32 unittype;
  HBA_UINT32 PortId;
  HBA_UINT32 NumberOfAttachedNodes;
  HBA_UINT16 IPVersion;
  HBA_UINT16 UDPPort;
  HBA_UINT8  IPAddress[16];
  HBA_UINT16 reserved;
  HBA_UINT16 TopologyDiscoveryFlags;
} HBA_MGMTINFO, *PHBA_MGMTINFO;