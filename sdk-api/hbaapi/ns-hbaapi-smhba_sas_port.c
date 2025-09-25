typedef struct SMHBA_SAS_Port {
  HBA_SASPORTPROTOCOL PortProtocol;
  HBA_WWN             LocalSASAddress;
  HBA_WWN             AttachedSASAddress;
  HBA_UINT32          NumberofDiscoveredPorts;
  HBA_UINT32          NumberofPhys;
} SMHBA_SAS_PORT, *PSMHBA_SAS_PORT;