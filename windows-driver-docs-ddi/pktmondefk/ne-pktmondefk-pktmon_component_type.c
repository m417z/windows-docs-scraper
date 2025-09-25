typedef enum _PKTMON_COMPONENT_TYPE {
  PktMonComp_Ndis,
  PktMonComp_Miniport,
  PktMonComp_Filter,
  PktMonComp_Protocol,
  PktMonComp_VmsVmNic,
  PktMonComp_VmsMiniport,
  PktMonComp_VmsExtMiniport,
  PktMonComp_VmsProtocolNic,
  PktMonComp_NetVsc,
  PktMonComp_HTTP,
  PktMonComp_IpInterface,
  PktMonComp_Slbmux,
  PktMonComp_Ipsec,
  PktMonComp_NetCx,
  PktMonComp_HTTPMessage
} PKTMON_COMPONENT_TYPE;