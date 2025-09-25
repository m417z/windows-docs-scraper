# _NDIS_SWITCH_PORT_PROPERTY_TYPE enumeration

## Description

The **NDIS_SWITCH_PORT_PROPERTY_TYPE** enumeration specifies the property type of a policy that is defined for a port on a Hyper-V extensible switch.

## Constants

### `NdisSwitchPortPropertyTypeUndefined`

The port property type is not defined.

### `NdisSwitchPortPropertyTypeCustom`

This value specifies a custom port property that is defined by an independent software vendor (ISV). Custom port properties are defined by using the [NDIS_SWITCH_PORT_PROPERTY_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_custom) structure.

### `NdisSwitchPortPropertyTypeSecurity`

This value specifies a security port property. Security port properties are defined by using the [NDIS_SWITCH_PORT_PROPERTY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_security) structure.

### `NdisSwitchPortPropertyTypeVlan`

This value specifies a virtual local area network (VLAN) port property. VLAN port properties are defined by using the [NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan) structure.

### `NdisSwitchPortPropertyTypeProfile`

This value specifies a profile port property. Profile port properties are defined by using the [NDIS_SWITCH_PORT_PROPERTY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_profile) structure.

### `NdisSwitchPortPropertyTypeIsolation`

This value specifies an isolation port property. Isolation port properties are defined by using the [NDIS_SWITCH_PORT_PROPERTY_ISOLATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_isolation) structure.

**Note** This value is supported in NDIS 6.40 and later.

### `NdisSwitchPortPropertyTypeRoutingDomain`

This value specifies a routing domain port property. Routing domain port properties are defined by using the [NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain) structure.

**Note** This value is supported in NDIS 6.40 and later.

### `NdisSwitchPortPropertyTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **PropertyType** member of the following structures is an **NDIS_SWITCH_PORT_PROPERTY_TYPE** enumeration data type:

* [NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_delete_parameters)
* [NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters)
* [NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters)
* [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)

For more information about extensible switch port policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters)

[NDIS_SWITCH_PORT_PROPERTY_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_custom)

[NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_delete_parameters)

[NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters)

[NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)

[NDIS_SWITCH_PORT_PROPERTY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_profile)

[NDIS_SWITCH_PORT_PROPERTY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_security)

[NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan)