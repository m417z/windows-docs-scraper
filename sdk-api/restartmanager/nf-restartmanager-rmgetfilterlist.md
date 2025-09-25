# RmGetFilterList function

## Description

Lists the modifications to shutdown and restart actions that have already been applied by the [RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter) function. The function returns a pointer to a buffer containing information about the modifications which have been applied.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

### `pbFilterBuf` [out, optional]

A pointer to a buffer that contains modification information.

### `cbFilterBuf` [in]

The size of the buffer that contains modification information in bytes.

### `cbFilterBufNeeded` [out]

The number of bytes needed in the buffer.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in as a parameter that requires a non-**null** and non-zero value. |
| **ERROR_MORE_DATA**<br><br>234 | This error value is returned by the [RmGetFilterList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetfilterlist) function if the *pbFilterBuf* buffer is too small to hold all the application information in the list or if *cbFilterBufNeeded* was not specified. |
| **ERROR_SESSION_CREDENTIAL_CONFLICT**<br><br>1219 | This error is returned when a secondary installer calls this function. This function is only available to primary installers. |

## Remarks

The returned *pbFilterBuf* buffer has to be typecast to **RM_FILTER_INFO** to access the filter list.

## See also

[RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter)