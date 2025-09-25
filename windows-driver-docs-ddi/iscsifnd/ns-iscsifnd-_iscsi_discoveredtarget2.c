typedef struct _ISCSI_DiscoveredTarget2 {
  ULONG                              TargetPortalGroupCount;
  WCHAR                              TargetName[223 + 1];
  WCHAR                              TargetAlias[255 + 1];
  ISCSI_DiscoveredTargetPortalGroup2 TargetDiscoveredPortalGroups[1];
} ISCSI_DiscoveredTarget2, *PISCSI_DiscoveredTarget2;