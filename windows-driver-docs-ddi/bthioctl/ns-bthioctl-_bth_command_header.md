# _BTH_COMMAND_HEADER structure

## Description

The BTH_COMMAND_HEADER structure specifies header information for a vendor-specific HCI
command.

## Members

### `OpCode`

A USHORT value that specifies the operation code for the command.

### `TotalParameterLength`

The size, in bytes, of the command payload, which is the data that follows the BTH_COMMAND_HEADER
structure.

## Remarks

The BTH_COMMAND_HEADER structure specifies header information in the
**HciHeader** member of the
[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command) structure. It also provides the header information for the output of
the
[IOCTL_BTH_HCI_VENDOR_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_hci_vendor_command) IOCTL.

## See also

[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command)

[IOCTL_BTH_HCI_VENDOR_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_hci_vendor_command)