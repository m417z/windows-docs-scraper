typedef enum _NDIS_SWITCH_PORT_PROPERTY_TYPE {
  NdisSwitchPortPropertyTypeUndefined,
  NdisSwitchPortPropertyTypeCustom,
  NdisSwitchPortPropertyTypeSecurity,
  NdisSwitchPortPropertyTypeVlan,
  NdisSwitchPortPropertyTypeProfile,
  NdisSwitchPortPropertyTypeIsolation,
  NdisSwitchPortPropertyTypeRoutingDomain,
  NdisSwitchPortPropertyTypeMaximum
} NDIS_SWITCH_PORT_PROPERTY_TYPE, *PNDIS_SWITCH_PORT_PROPERTY_TYPE;