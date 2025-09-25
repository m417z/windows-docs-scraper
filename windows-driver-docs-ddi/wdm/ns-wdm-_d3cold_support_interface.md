# _D3COLD_SUPPORT_INTERFACE structure

## Description

The **D3COLD_SUPPORT_INTERFACE** interface structure contains pointers to the routines in the D3COLD Support Interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version. The current version of this interface is D3COLD_SUPPORT_INTERFACE_VERSION.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `SetD3ColdSupport`

A pointer to a [SetD3ColdSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_d3cold_support) routine that enables or disables transitions to the D3cold device power state.

### `GetIdleWakeInfo`

A pointer to a [GetIdleWakeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info) routine that the device driver calls to discover the device power states from which this device can signal wake events to the processor.

### `GetD3ColdCapability`

A pointer to a [GetD3ColdCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh967711(v=vs.85)) routine that reports whether this device is capable of entering the D3cold device power state.

### `GetBusDriverD3ColdSupport`

A pointer to a [GetBusDriverD3ColdSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_d3cold_capability) routine that reports whether the underlying bus driver and ACPI system firmware support D3cold for this device.

### `GetLastTransitionStatus`

A pointer to a [GetLastTransitionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_d3cold_last_transition_status) routine that reports whether this device's most recent transition to D3hot was followed by a transition to D3cold.

## Remarks

A device driver that successfully queries for the GUID_D3COLD_SUPPORT_INTERFACE interface receives a pointer to a **D3COLD_SUPPORT_INTERFACE** structure in which the pointers to the routines in the interface are all non-NULL and valid.

The **D3COLD_SUPPORT_INTERFACE** structure is an extended version of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

## See also

[GetBusDriverD3ColdSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_d3cold_capability)

[GetD3ColdCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh967711(v=vs.85))

[GetIdleWakeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info)

[GetLastTransitionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_d3cold_last_transition_status)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)

[SetD3ColdSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_d3cold_support)