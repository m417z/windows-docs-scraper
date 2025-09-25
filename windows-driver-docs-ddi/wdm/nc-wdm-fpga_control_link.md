## Description

Reserved for future use.

Enables or disables the link between the given FPGA device and its parent bridge.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the bus extension.

### `Enable` [_In_]

A boolean value that indicates whether the link should be enabled or disabled. TRUE indicates enabled; FALSE otherwise.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A device driver that successfully queries for the GUID_PCI_FPGA_CONTROL_INTERFACE interface receives a pointer to a [**FPGA_CONTROL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fpga_control_interface) structure in which the driver sets the **ControlLink** member to a pointer to its implementation of the _FPGA_CONTROL_CONFIG_SPACE_ callback function.

## See also