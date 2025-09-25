# _FPGA_CONTROL_INTERFACE structure

## Description

Reserved for future use.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version. The current version of this interface is FPGA_CONTROL_INTERFACE_VERSION.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `BusScan`

A pointer to a [_FPGA_BUS_SCAN_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-fpga_bus_scan) callback function that triggers a bus scan at the parent of the FPGA device.

### `ControlLink`

A pointer to a [_FPGA_CONTROL_LINK_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-fpga_control_link) callback function that enables or disables the link between the given FPGA device and its parent bridge.

### `ControlConfigSpace`

A pointer to a [_FPGA_CONTROL_CONFIG_SPACE_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-fpga_control_config_space) callback function that enables or disables the access to the configuration space of the FPGA device.

### `ControlErrorReporting`

A pointer to a [_FPGA_CONTROL_ERROR_REPORTING_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-fpga_control_error_reporting) callback function that toggles the error reporting for the FPGA device and its parent bridge.

## Remarks

A device driver that successfully queries for the GUID_PCI_FPGA_CONTROL_INTERFACE interface receives a pointer to a [**_FPGA_CONTROL_INTERFACE**] structure in which the pointers to the routines in the interface are all non-NULL and valid.

The [**_FPGA_CONTROL_INTERFACE**] structure is an extended version of the [INTERFACE] structure.

## See also