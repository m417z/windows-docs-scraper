# STORAGE_DIAGNOSTIC_REQUEST structure

## Description

Describes a diagnostic request about the storage driver stack. The **STORAGE_DIAGNOSTIC_REQUEST** structure is provided in the input buffer of an [**IOCTL_STORAGE_DIAGNOSTIC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_diagnostic) request.

## Members

### `Version`

Version of this structure.

### `Size`

Specifies the whole size of the structure and the associated data buffer.

### `Flags`

Specifies the request flag.

### `TargetType`

Specifies the request target type. See definitions for [**STORAGE_DIAGNOSTIC_TARGET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_target_type).

### `Level`

Specifies the Diagnostic level. See definitions for [**STORAGE_DIAGNOSTIC_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_level).

## See also

[**IOCTL_STORAGE_DIAGNOSTIC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_diagnostic)

[**STORAGE_DIAGNOSTIC_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_data)

[**STORAGE_DIAGNOSTIC_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_level)

[**STORAGE_DIAGNOSTIC_TARGET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_target_type)