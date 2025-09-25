typedef struct _MS_SMHBA_SAS_Port {
  ULONG PortProtocol;
  UCHAR LocalSASAddress[8];
  UCHAR AttachedSASAddress[8];
  ULONG NumberofDiscoveredPorts;
  ULONG NumberofPhys;
} MS_SMHBA_SAS_Port, *PMS_SMHBA_SAS_Port;