# _PEP_QUERY_COMPONENT_PERF_SET structure (pep_x.h)

## Description

The **PEP_QUERY_COMPONENT_PERF_SET** structure contains query information about a set of performance state values (P-state set) for a component.

## Members

### `DeviceHandle`

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component`

The index that identifies the component. This member is an index into the *Components* array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the *Components* array contains N elements, component indexes range from 0 to N–1.

### `Set`

The index that identifies this P-state set. If this component has M P-state sets, P-state set indexes range from 0 to M–1. The PEP previously specified the number of P-state sets in response to a [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification.

### `Flags`

A set of input flags. No flag bits are currently defined for this member, which is always zero.

### `Unit`

A [PEP_PERF_STATE_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_unit) enumeration value that indicates whether the values for this P-state set are expressed in hertz (frequency units) or bits per second (bandwidth units).

### `Type`

A [PEP_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_type) enumeration value that indicates whether the performance values for this P-state set are expressed as a list of discrete values or as a continuous range of values.

### `Discrete`

Use this structure if `Type == PepPerfStateTypeDiscrete`.

### `Discrete.Count`

The number of discrete performance values in this P-state set.

### `Range`

Use this structure if `Type == PepPerfStateTypeRange`.

### `Range.Minimum`

The minimum value in the range of performance values for this P-state set. This value is expressed in the measurement units indicated by the *Unit* member.

### `Range.Maximum`

The maximum value in the range of performance values for this P-state set. This value is expressed in the measurement units indicated by the *Unit* member.

## Remarks

The unnamed union represents either the number of discrete performance values in this P-state set, or the range of values in this P-state set.

This structure is used by the [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set) notification. The *DeviceHandle*, *Component*, *Set*, and *Flags* members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent. The *Discrete* member or *Range* member contains an output value that the PEP writes to the structure in response to the notification.

## See also

- [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)
- [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set)
- [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)
- [PEP_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_type)
- [PEP_PERF_STATE_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_unit)