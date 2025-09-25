typedef struct _ISCSI_DiscoveredTargetPortalGroup2 {
  ULONG                         PortalCount;
  USHORT                        Tag;
  ISCSI_DiscoveredTargetPortal2 Portals[1];
} ISCSI_DiscoveredTargetPortalGroup2, *PISCSI_DiscoveredTargetPortalGroup2;