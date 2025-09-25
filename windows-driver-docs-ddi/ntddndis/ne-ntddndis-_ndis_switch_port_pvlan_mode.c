typedef enum _NDIS_SWITCH_PORT_PVLAN_MODE {
  NdisSwitchPortPvlanModeUndefined,
  NdisSwitchPortPvlanModeIsolated,
  NdisSwitchPortPvlanModeCommunity,
  NdisSwitchPortPvlanModePromiscuous
} NDIS_SWITCH_PORT_PVLAN_MODE, *PNDIS_SWITCH_PORT_PVLAN_MODE;