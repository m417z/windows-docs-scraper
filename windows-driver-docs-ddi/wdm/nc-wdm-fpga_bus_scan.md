## Description

Reserved for future use.

Triggers a bus scan at the parent of the FPGA device.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the bus extension.

## Remarks

A device driver that successfully queries for the GUID_PCI_FPGA_CONTROL_INTERFACE interface receives a pointer to a [**FPGA_CONTROL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fpga_control_interface) structure in which the driver sets the **BusScan** member to a pointer to its implementation of the _FPGA_BUS_SCAN_ callback function.

## See also