# _SYSENV_VARIABLE structure

## Description

Stores the name a system environment variable using
SysEnv device. This structure is used in the [IOCTL_SYSENV_GET_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_get_variable) request.

## Members

### `VendorGuid`

The vendor GUID.

### `VariableNameLength`

The length of the string pointed to by **VariableName**, which contains the name of the variable.

### `VariableName`

A string that contains the name of the variable.

## See also

[IOCTL_SYSENV_GET_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_get_variable)