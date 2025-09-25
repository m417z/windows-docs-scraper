## Description

The BPIO_OUTPUT structure is used to return information about the BypassIO operation for the [**IOCTL_STORAGE_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_bypass_io) control code.

## Members

### `Version`

The version of this structure. Set to ```sizeof(BPIO_OUTPUT)```.

### `Size`

The size of this structure plus all of its variable-sized fields, in bytes.

### `Operation`

A [**BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_operations) enum value that identifies the requested BypassIO operation. This field should be set to the same value passed in [**BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_input)**.Operation**.

### `OutFlags`

A [**BPIO_OUTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_outflags) enum value that specifies the output flags for the operation.

### `Reserved2`

Reserved for system use. Set to zero.

### `Enable`

A [**BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_results) structure in which to write the results when a [BPIO_OP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_operations) operation was requested.

### `Query`

A [**BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_results) structure in which to write the results when a [BPIO_OP_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_operations) operation was requested.

## Remarks

See [BypassIO for storage drivers](https://learn.microsoft.com/windows-hardware/drivers/storage/bypassio) for more information.

## See also

[**BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_operations)

[**BPIO_OUTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_outflags)

[**BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_results)

[**IOCTL_STORAGE_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_bypass_io)