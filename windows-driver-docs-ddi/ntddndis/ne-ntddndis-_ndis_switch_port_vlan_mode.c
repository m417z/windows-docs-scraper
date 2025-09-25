typedef enum _NDIS_SWITCH_PORT_VLAN_MODE {
  NdisSwitchPortVlanModeUnknown,
  NdisSwitchPortVlanModeAccess,
  NdisSwitchPortVlanModeTrunk,
  NdisSwitchPortVlanModePrivate,
  NdisSwitchPortVlanModeMax
} NDIS_SWITCH_PORT_VLAN_MODE, *PNDIS_SWITCH_PORT_VLAN_MODE;