## Description

Reserved for future use.

Toggles the error reporting for the FPGA device and its parent bridge.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the bus extension.

### `UncorrectableMask` [_In_]

A bitwise mask of flags defined in [**PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_mask) that indicates the uncorrectable masks to be toggled.

### `CorrectableMask` [_In_]

 A bitwise mask of flags defined in [**PCI_EXPRESS_CORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_correctable_error_mask) that indicates the correctable masks to be toggled.

### `DisableErrorReporting` [_In_]

A flag indicates whether the error reporting is being disabled or enabled.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A device driver that successfully queries for the GUID_PCI_FPGA_CONTROL_INTERFACE interface receives a pointer to a [**FPGA_CONTROL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fpga_control_interface) structure in which the driver sets the **ControlErrorReporting** member to a pointer to its implementation of the _FPGA_CONTROL_CONFIG_SPACE_ callback function.

- This callback function expects that the FPGA device is in D0 state and its configuration space has not been locked.

- When _DisableErrorReporting_ is set to TRUE, each set bit in the given masks is set in the AER capability of the FPGA device. When _DisableErrorReporting_ is set to FALSE, the original AER masks will be restored.

## See also