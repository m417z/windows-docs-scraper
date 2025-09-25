typedef struct SMHBA_FC_Port {
  HBA_WWN      NodeWWN;
  HBA_WWN      PortWWN;
  HBA_UINT32   FcId;
  HBA_COS      PortSupportedClassofService;
  HBA_FC4TYPES PortSupportedFc4Types;
  HBA_FC4TYPES PortActiveFc4Types;
  HBA_WWN      FabricName;
  char         PortSymbolicName[256];
  HBA_UINT32   NumberofDiscoveredPorts;
  HBA_UINT8    NumberofPhys;
} SMHBA_FC_PORT, *PSMHBA_FC_PORT;