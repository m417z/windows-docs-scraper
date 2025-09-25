# _NDIS_SWITCH_FEATURE_STATUS_TYPE enumeration

## Description

The **NDIS_SWITCH_FEATURE_STATUS_TYPE** enumeration specifies the type of status information for a custom policy property, or *feature*, of a Hyper-V extensible switch.

An extensible switch feature is defined and supported by an independent software vendor (ISV).

## Constants

### `NdisSwitchFeatureStatusTypeUndefined`

The feature status information is not defined.

### `NdisSwitchFeatureStatusTypeCustom`

The feature status information is for a custom extensible switch feature that is provided by an ISV.

### `NdisSwitchFeatureStatusTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **FeatureStatusType** member of the [NDIS_SWITCH_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_parameters) structure is an [NDIS_SWITCH_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_property_type) enumeration data type.

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_SWITCH_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_parameters)