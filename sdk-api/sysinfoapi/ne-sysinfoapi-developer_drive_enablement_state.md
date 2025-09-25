# DEVELOPER_DRIVE_ENABLEMENT_STATE enumeration

## Description

An enum of possible values for the developer drive enablement state.

## Constants

### `DeveloperDriveEnablementStateError`

Indicates that there was an error determining the developer drive enablement state. After this is returned, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get the error value.

### `DeveloperDriveEnabled`

Indicates that the developer drive is enabled.

### `DeveloperDriveDisabledBySystemPolicy`

Indicates that the developer drive is disabled by system policy.

### `DeveloperDriveDisabledByGroupPolicy`

Indicates that the developer drive is disabled by group policy.

## Remarks

## See also

[GetDeveloperDriveEnablementState](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getdeveloperdriveenablementstate)