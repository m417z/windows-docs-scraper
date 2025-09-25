## Description

A **SET_PURGE_FAILURE_MODE_INPUT** structure is the input parameter for an [**FSCTL_SET_PURGE_FAILURE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_set_purge_failure_mode) operation.

## Members

### `Flags`

Flags for the operation. Can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| SET_PURGE_FAILURE_MODE_ENABLED | Enables purge failure mode |
| SET_PURGE_FAILURE_MODE_DISABLED | Disables purge failure mode |

## See also

[**FSCTL_SET_PURGE_FAILURE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_set_purge_failure_mode)