# _NDIS_SWITCH_PROPERTY_TYPE enumeration

## Description

The **NDIS_SWITCH_PROPERTY_TYPE** enumeration specifies the type of policy property for a Hyper-V extensible switch.

## Constants

### `NdisSwitchPropertyTypeUndefined`

The switch property type is not defined.

### `NdisSwitchPropertyTypeCustom`

This value specifies a custom switch property that is defined by an independent software vendor (ISV).

### `NdisSwitchPropertyTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **PropertyType** member of the following structures is an **NDIS_SWITCH_PROPERTY_TYPE** enumeration data type:

* [NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_delete_parameters)
* [NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_parameters)
* [NDIS_SWITCH_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_parameters)

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_delete_parameters)

[NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_parameters)

[NDIS_SWITCH_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_parameters)