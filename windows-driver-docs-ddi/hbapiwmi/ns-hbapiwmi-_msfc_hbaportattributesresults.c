typedef struct _MSFC_HBAPortAttributesResults {
  UCHAR NodeWWN[8];
  UCHAR PortWWN[8];
  ULONG PortFcId;
  ULONG PortType;
  ULONG PortState;
  ULONG PortSupportedClassofService;
  UCHAR PortSupportedFc4Types[32];
  UCHAR PortActiveFc4Types[32];
  ULONG PortSupportedSpeed;
  ULONG PortSpeed;
  ULONG PortMaxFrameSize;
  UCHAR FabricName[8];
  ULONG NumberofDiscoveredPorts;
} MSFC_HBAPortAttributesResults, *PMSFC_HBAPortAttributesResults;