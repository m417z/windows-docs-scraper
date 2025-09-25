# _XVARIABLE_NAME structure

## Description

Stores the name of a system environment variable using
SysEnv device. This structure is used in the [IOCTL_SYSENV_ENUM_VARIABLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_enum_variables) request.

## Members

### `NextEntryOffset`

The location of the next entry in the array of **XVARIABLE_NAME** structures reprieved by the [IOCTL_SYSENV_ENUM_VARIABLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_enum_variables) request.

### `VendorGuid`

The vendor GUID.

### `Name`

Name of the system environment variable.

## See also

[IOCTL_SYSENV_ENUM_VARIABLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_enum_variables)