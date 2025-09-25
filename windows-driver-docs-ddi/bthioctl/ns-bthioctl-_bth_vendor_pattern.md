# _BTH_VENDOR_PATTERN structure

## Description

The BTH_VENDOR_PATTERN structure specifies a vendor pattern.

## Members

### `Offset`

The offset, in bytes, of the pattern from the beginning of the event data, excluding the event
header.

### `Size`

The size, in bytes, of the pattern.

### `Pattern`

A buffer that contains pattern data.

## Remarks

The BTH_VENDOR_PATTERN structure specifies vendor patterns for the
[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command) structure.

A list of patterns can immediately follow the vendor-specific command data that is specified in the
**Data** member of the BTH_VENDOR_SPECIFIC_COMMAND structure.

Patterns are required if a vendor-specific command does not follow the standard HCI flow control and a
vendor-specific event is generated in response to the vendor-specific command.

## See also

[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command)