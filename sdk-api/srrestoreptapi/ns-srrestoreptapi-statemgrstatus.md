# STATEMGRSTATUS structure

## Description

Contains status information used by the
[SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srsetrestorepointa) function.

## Members

### `nStatus`

The status code. For a list of values, see the Remarks section.

### `llSequenceNumber`

The sequence number of the restore point.

## Remarks

The following table lists the status codes returned in the **nStatus** member. Note that all the status codes indicate failure except ERROR_SUCCESS.

| Status Code | Meaning |
| --- | --- |
| ERROR_SUCCESS | The call succeeded. |
| ERROR_BAD_ENVIRONMENT | The function was called in safe mode. |
| ERROR_DISK_FULL | System Restore is in standby mode because disk space is low. |
| ERROR_INTERNAL_ERROR | An internal error occurred. |
| ERROR_INVALID_DATA | The sequence number is invalid. |
| ERROR_SERVICE_DISABLED | System Restore is disabled. |
| ERROR_TIMEOUT | The call timed out due to a wait on a mutex for setting restore points. |

## See also

[SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srsetrestorepointa)