typedef struct _ISCSI_DiscoveredTargetPortalGroup {
  ULONG                        PortalCount;
  ISCSI_DiscoveredTargetPortal Portals[1];
} ISCSI_DiscoveredTargetPortalGroup, *PISCSI_DiscoveredTargetPortalGroup;