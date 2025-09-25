# _SYSENV_VALUE structure

## Description

Stores the value of a system environment variable using SysEnv device. This structure is used in the [IOCTL_SYSENV_GET_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_get_variable) request.

## Members

### `Attributes`

Attributes of the system environment variable.

### `ValueLength`

The length of the value of the system environment variable.

### `ValueData[ANYSIZE_ARRAY]`

The value of the system environment variable.

## See also

- [IOCTL_SYSENV_GET_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_get_variable)