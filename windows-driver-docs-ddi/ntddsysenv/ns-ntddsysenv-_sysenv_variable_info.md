# _SYSENV_VARIABLE_INFO structure

## Description

Stores the information about a system environment variable using
SysEnv device. This structure is used in the [IOCTL_SYSENV_QUERY_VARIABLE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_query_variable_info) request.

## Members

### `MaximumVariableStorageSize`

The size of the variable.

### `RemainingVariableStorageSize`

The remaining size of the variable.

### `MaximumVariableSize`

The maximum size of the variable.

## See also

[IOCTL_SYSENV_QUERY_VARIABLE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ni-ntddsysenv-ioctl_sysenv_query_variable_info)