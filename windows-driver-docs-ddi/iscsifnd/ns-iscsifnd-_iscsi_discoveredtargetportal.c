typedef struct _ISCSI_DiscoveredTargetPortal {
  USHORT           Socket;
  ISCSI_IP_Address Address;
  WCHAR            SymbolicName[256 + 1];
} ISCSI_DiscoveredTargetPortal, *PISCSI_DiscoveredTargetPortal;