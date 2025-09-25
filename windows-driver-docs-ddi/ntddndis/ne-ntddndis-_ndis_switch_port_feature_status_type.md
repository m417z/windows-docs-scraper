# _NDIS_SWITCH_PORT_FEATURE_STATUS_TYPE enumeration

## Description

The **NDIS_SWITCH_PORT_FEATURE_STATUS_TYPE** enumeration specifies the type of status information for a proprietary policy property, or *feature*, of a Hyper-V extensible switch port.

An extensible switch port feature is defined and supported by an independent software vendor (ISV).

## Constants

### `NdisSwitchPortFeatureStatusTypeUndefined`

The port feature status information is not defined.

### `NdisSwitchPortFeatureStatusTypeCustom`

The feature status information is for a custom extensible switch port feature that is provided by an ISV.

### `NdisSwitchPortFeatureStatusTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **FeatureStatusType** member of the [NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters) structure is an **NDIS_SWITCH_PORT_FEATURE_STATUS_TYPE** enumeration data type.

For more information about extensible switch port policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters)