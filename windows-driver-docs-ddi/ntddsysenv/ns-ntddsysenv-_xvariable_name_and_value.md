# _XVARIABLE_NAME_AND_VALUE structure

## Description

Stores the name and value of a system environment variable using
SysEnv device. This structure is used in the [IOCTL_SYSENV_ENUM_VARIABLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_enum_variables) and [IOCTL_SYSENV_SET_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_set_variable) requests.

## Members

### `NextEntryOffset`

The location of the next entry in the array of XVARIABLE_NAME structures reprieved by the [IOCTL_SYSENV_ENUM_VARIABLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_enum_variables) request.

### `ValueOffset`

The value of the system environment variable.

### `ValueLength`

The length of the value.

### `Attributes`

Attributes of the system environment variable.

### `VendorGuid`

The vendor GUID.

### `Name`

Name of the system environment variable.

## See also

[IOCTL_SYSENV_ENUM_VARIABLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_enum_variables)

[IOCTL_SYSENV_SET_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_set_variable)