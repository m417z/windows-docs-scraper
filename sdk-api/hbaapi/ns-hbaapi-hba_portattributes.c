typedef struct HBA_PortAttributes {
  HBA_WWN       NodeWWN;
  HBA_WWN       PortWWN;
  HBA_UINT32    PortFcId;
  HBA_PORTTYPE  PortType;
  HBA_PORTSTATE PortState;
  HBA_COS       PortSupportedClassofService;
  HBA_FC4TYPES  PortSupportedFc4Types;
  HBA_FC4TYPES  PortActiveFc4Types;
  char          PortSymbolicName[256];
  char          OSDeviceName[256];
  HBA_PORTSPEED PortSupportedSpeed;
  HBA_PORTSPEED PortSpeed;
  HBA_UINT32    PortMaxFrameSize;
  HBA_WWN       FabricName;
  HBA_UINT32    NumberofDiscoveredPorts;
} HBA_PORTATTRIBUTES, *PHBA_PORTATTRIBUTES;