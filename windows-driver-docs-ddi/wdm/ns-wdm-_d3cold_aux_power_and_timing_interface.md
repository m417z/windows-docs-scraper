# _D3COLD_AUX_POWER_AND_TIMING_INTERFACE structure

## Description

An extended version of the INTERFACE structure that allows device drivers to negotiate a higher auxiliary power for their PCI devices while in D3Cold state. This interface allows device drivers to invoke the functions that manipulate _DSM functions 0Ah, 0Bh.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version. The current version of this interface is D3COLD_AUX_POWER_AND_TIMING_INTERFACE_VERSION.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `RequestCorePowerRail`

A pointer to a [_D3COLD_REQUEST_CORE_POWER_RAIL_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-d3cold_request_core_power_rail) callback function that enables the function device object (FDO) to indicate whether the core power rail is needed.

### `RequestAuxPower`

A pointer to a [_D3COLD_REQUEST_AUX_POWER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-d3cold_request_aux_power) callback function that enables the function device object (FDO) to convey its auxiliary power requirement.

### `RequestPerstDelay`

A pointer to a [_D3COLD_REQUEST_PERST_DELAY_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-d3cold_request_perst_delay) enables the function device object (FDO) to convey its requirement for a fixed delay time.

## Remarks

A device driver that successfully queries for the GUID_D3COLD_AUX_POWER_AND_TIMING_INTERFACE interface receives a pointer to a [**D3COLD_AUX_POWER_AND_TIMING_INTERFACE**] structure in which the pointers to the routines in the interface are all non-NULL and valid.

The [**D3COLD_AUX_POWER_AND_TIMING_INTERFACE**] structure is an extended version of the [INTERFACE] structure.

Windows now has added support for the newly introduced [PCI Device Specific Method (_DSM) functions for Runtime Device Power Management](https://members.pcisig.com/wg/PCI-SIG/document/11119). The new interfaces listed below allow device drivers to negotiate a higher auxiliary power for their PCI devices (higher than the standard 375mA @ 3.3V), if their devices require additional power while in D3Cold state. All device drivers must be able to handle the cases where additional power cannot be provided by the system, or if the interfaces are not supported.

All PCIe ports that support the [_DSM functions for Runtime Device Power Management](https://members.pcisig.com/wg/PCI-SIG/document/11119), must implement the Device Specific Data (_DSD) for [Identifying PCIe ports supporting D3_COLD_AUX_POWER ECN Interface](https://learn.microsoft.com/windows-hardware/drivers/pci/dsd-for-pcie-root-ports#identifying-pcie-ports-supporting-d3_cold_aux_power-ecn-interface) under the ACPI scope of the PCIe port.

## See also

[_D3COLD_REQUEST_CORE_POWER_RAIL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-d3cold_request_core_power_rail)

[_D3COLD_REQUEST_AUX_POWER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-d3cold_request_aux_power)

[_D3COLD_REQUEST_PERST_DELAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-d3cold_request_perst_delay)

[Identifying PCIe ports supporting D3_COLD_AUX_POWER ECN Interface](https://learn.microsoft.com/windows-hardware/drivers/pci/dsd-for-pcie-root-ports#identifying-pcie-ports-supporting-d3_cold_aux_power-ecn-interface)