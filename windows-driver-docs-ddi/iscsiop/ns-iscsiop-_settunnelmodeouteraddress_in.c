typedef struct _SetTunnelModeOuterAddress_IN {
  ULONG            PortNumber;
  ISCSI_IP_Address DestinationAddress;
  ISCSI_IP_Address TunnelModeOuterAddress;
} SetTunnelModeOuterAddress_IN, *PSetTunnelModeOuterAddress_IN;