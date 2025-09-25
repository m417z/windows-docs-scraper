## Description

STORAGE_REINITIALIZE_MEDIA is an optional structure that contains sanitize parameters for [**IOCTL_STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_reinitialize_media).

## Members

### `Version`

The version of this structure. Set to ```sizeof(STORAGE_REINITIALIZE_MEDIA)```.

### `Size`

The size of this structure, in bytes. Set to ```sizeof(STORAGE_REINITIALIZE_MEDIA)```.

### `TimeoutInSeconds`

Time out value for the sanitize, in seconds.

### `SanitizeOption`

Structure that specifies sanitize operation options. **SanitizeOption** only applies to NVMe devices.

### `SanitizeOption.SanitizeMethod`

A [**STORAGE_SANITIZE_METHOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_sanitize_method) value that specifies the sanitize method to use.

### `SanitizeOption.DisallowUnrestrictedSanitizeExit`

Indicates whether unrestricted sanitize exit is allowed. By default, unrestricted sanitize exit is allowed (set to 1).

### `SanitizeOption.Reserved`

Reserved. Do not use.

## See also

[**IOCTL_STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_reinitialize_media)

[**STORAGE_SANITIZE_METHOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_sanitize_method)