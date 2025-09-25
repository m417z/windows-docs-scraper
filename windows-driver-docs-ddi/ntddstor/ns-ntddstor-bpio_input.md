## Description

The BPIO_INPUT structure specifies the requested BypassIO operation and flags for the [**IOCTL_STORAGE_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_bypass_io) control code.

## Members

### `Version`

The version of this structure. Set to ```sizeof(BPIO_INPUT)```.

### `Size`

The size of this structure plus all of its variable-sized fields, in bytes.

### `Operation`

A [**BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_operations) enum value that identifies the requested BypassIO operation.

### `InFlags`

A [**BPIO_INFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_inflags) enum value that specifies the input flags for the operation.

### `Reserved2`

Reserved for system use. Must be set to zero.

## Remarks

See [BypassIO for storage drivers](https://learn.microsoft.com/windows-hardware/drivers/storage/bypassio) for more information.

## See also

[**BPIO_INFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_inflags)

[**BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-bpio_operations)

[**IOCTL_STORAGE_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_bypass_io)