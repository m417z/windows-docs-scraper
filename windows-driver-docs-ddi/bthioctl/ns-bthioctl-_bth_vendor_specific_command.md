# _BTH_VENDOR_SPECIFIC_COMMAND structure

## Description

The BTH_VENDOR_SPECIFIC_COMMAND structure specifies a Bluetooth vendor-specific command.

## Members

### `ManufacturerId`

The manufacturer identifier of the radio. Radios that have this manufacturer identifier can
receive the vendor-specific command.

### `LmpVersion`

A UCHAR that contains the link management protocol (LMP) version. If the LMP version of a radio is
greater than this value, the command is sent to the radio. Otherwise, the radio does not receive the
command. If
**LmpVersion** is zero, all radios will receive the vendor-specific command.

### `MatchAnySinglePattern`

A BOOLEAN value that specifies if all the patterns in the
**Data** member must match or only one pattern must match to associate an event with a vendor-specific
command. If there are no patterns that are associated with a vendor-specific command, this member is
ignored. If
**MatchAnySinglePattern** is **FALSE**, all the patterns must match to associate an event with the
command. If
**MatchAnySinglePattern** is **TRUE**, matching any pattern associates an event with the command.

### `HciHeader`

A
[BTH_COMMAND_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_command_header) structure that
contains information about the vendor-specific command that includes an operation code and buffer
length. The buffer length should only include the size of the data to be sent to the radio. It should
not include the size of the patterns.

### `Data`

A UCHAR array that contains the data and patterns for the command that is specified in the
**HciHeader** member. Patterns are specified with
[BTH_VENDOR_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_pattern) structures.

## Remarks

This BTH_VENDOR_SPECIFIC_COMMAND structure specifies the input buffer for the
[IOCTL_BTH_HCI_VENDOR_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_hci_vendor_command) IOCTL. This IOCTL can be used to send vendor-specific commands to
Bluetooth radios.

To specify the size of the HCI command data, use the
**TotalParameterLength** member in the
[BTH_COMMAND_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_command_header) structure in the
BTH_VENDOR_SPECIFIC_COMMAND structure's
**HciHeader** member.

Patterns are required if a vendor-specific command does not follow the standard HCI flow control and a
vendor-specific event is generated in response to the vendor-specific command.

If patterns are required, the patterns follow the data to be sent to the radio in the
**Data** member buffer. Each pattern begins with a
[BTH_VENDOR_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_pattern) structure.

If such patterns are specified, the
**TotalParameterLength** member should not include the size of the patterns.

## See also

[BTH_COMMAND_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_command_header)

[BTH_VENDOR_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_pattern)

[IOCTL_BTH_HCI_VENDOR_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_hci_vendor_command)