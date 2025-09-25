# _PEP_COMPONENT_PERF_SET structure (pep_x.h)

## Description

The **PEP_COMPONENT_PERF_SET** structure describes the performance states (P-states) in a P-state set.

## Members

### `Name`

An optional string that describes the device property controlled by this P-state set. For example, this string might be "Clock frequency" or "Memory bandwidth". If no such string is available for this P-state, the **Name** member is set to NULL. Otherwise, this member contains a pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the string.

### `Flags`

Set to zero. No flag bits are currently defined for this member.

### `Unit`

A [PEP_PERF_STATE_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_unit) structure that specifies the units in which the performance values for this P-state set are expressed. Component performance can be expressed in hertz (frequency) or in bits per second (bandwidth).

### `Type`

A [PEP_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_type) enumeration value that indicates the type of performance information that is specified for this component. This member indicates whether the performance values for this P-state set are specified as a list of discrete values or as a continuous range of values.

### `Discrete`

The list of discrete performance values for this P-state set.

### `Discrete.Count`

The number of P-states in this P-state set.

### `Discrete.States`

A pointer to an array of [PEP_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_perf_state) structures, each of which describes a discrete performance value in this P-state set. The **Count** member specifies the number of elements in this array. A P-state is identified by its array index. If the array contains N elements, P-state indexes range from 0 to N–1.

### `Range`

The range of discrete performance measurement values for this P-state set.

### `Range.Minimum`

The minimum value in the range. This value is expressed in the units indicated by the **Unit** member.

### `Range.Maximum`

The maximum value in the range. This value is expressed in the units indicated by the **Unit** member.

## Remarks

The unnamed union contains the performance measurement values for this P-state. This union contains either a list of discrete values (if `Type == PepPerfStateTypeDiscrete`) or a continuous range of values (if `Type == PepPerfStateTypeRange`).

The **PerfStateSets** member of the [PEP_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_info) is the first element in an array of **PEP_COMPONENT_PERF_SET** structures. All members of the **PEP_COMPONENT_PERF_SET** structure contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The platform extension plug-in (PEP) must not write to this structure.

Device drivers use the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure, which is similar to the **PEP_COMPONENT_PERF_SET** structure.

## See also

- [PEP_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_info)
- [PEP_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_perf_state)
- [PEP_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_type)
- [PEP_PERF_STATE_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_perf_state_unit)
- [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set)
- [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)