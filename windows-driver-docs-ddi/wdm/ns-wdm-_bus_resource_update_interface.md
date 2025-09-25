# _BUS_RESOURCE_UPDATE_INTERFACE structure

## Description

Enables device drivers to make direct calls to parent bus driver routines. This structure defines the GUID_BUS_RESOURCE_UPDATE_INTERFACE interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version. Current version is PCI_FPB_RESOURCE_UPDATE_INTERFACE_VERSION.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [**InterfaceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [**InterfaceDereference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `GetUpdatedBusResource`

A pointer to the busdriver-implemented callback function that is invoked to retrieve the updated resource information. See [**GET_UPDATED_BUS_RESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_updated_bus_resource)

## Remarks

The BUS_RESOURCE_UPDATE_INTERFACE structure is an extension of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

## See also