## Description

Reserved for future use.

Enables or disables the access to the configuration space of the FPGA device.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the bus extension.

### `Enable` [_In_]

A boolean value that indicates whether the configuration space access should be enabled or disabled. TRUE indicates enabled; FALSE otherwise.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A device driver that successfully queries for the GUID_PCI_FPGA_CONTROL_INTERFACE interface receives a pointer to a [**FPGA_CONTROL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fpga_control_interface) structure in which the driver sets the **ControlConfigSpace** member to a pointer to its implementation of the _FPGA_CONTROL_CONFIG_SPACE_ callback function.

- This callback function toggles the configuration space access to all the functions of the FPGA device.

- When the configuration space is locked down, all read accesses return FF and all write accesses are discarded.

- Until the configuration space is unlocked, the FPGA device is not reported to PNP as missing even when reading its configuration space returns FF.

- If there exists any active bus scan, it is not safe to lock down configuration space as it might confuse the scan bus.

## See also