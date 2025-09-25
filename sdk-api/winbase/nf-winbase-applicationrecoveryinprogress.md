# ApplicationRecoveryInProgress function

## Description

Indicates that the calling application is continuing to recover data.

## Parameters

### `pbCancelled` [out]

Indicates whether the user has canceled the recovery process. Set by WER if the user clicks the Cancel button.

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | You can call this function only after Windows Error Reporting has called your recovery callback function. |
| **E_INVALIDARG** | The *pbCancelled* cannot be **NULL**. |

## Remarks

The application must call this function within the interval specified when calling the [RegisterApplicationRecoveryCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrecoverycallback) function. If the application fails to call this function within the specified interval, WER terminates the application. The recovery process can continue as long as this function is being called.

If the user cancels the recovery process, the application should terminate.

To indicate that the recovery process has been completed, call the [ApplicationRecoveryFinished](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-applicationrecoveryfinished) function.

## See also

[ApplicationRecoveryFinished](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-applicationrecoveryfinished)

[RegisterApplicationRecoveryCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrecoverycallback)