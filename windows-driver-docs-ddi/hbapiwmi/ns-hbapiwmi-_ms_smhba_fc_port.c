typedef struct _MS_SMHBA_FC_Port {
  UCHAR NodeWWN[8];
  UCHAR PortWWN[8];
  ULONG FcId;
  ULONG PortSupportedClassofService;
  UCHAR PortSupportedFc4Types[32];
  UCHAR PortActiveFc4Types[32];
  UCHAR FabricName[8];
  ULONG NumberofDiscoveredPorts;
  UCHAR NumberofPhys;
  WCHAR PortSymbolicName[256 + 1];
} MS_SMHBA_FC_Port, *PMS_SMHBA_FC_Port;