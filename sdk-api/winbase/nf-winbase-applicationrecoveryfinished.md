# ApplicationRecoveryFinished function

## Description

Indicates that the calling application has completed its data recovery.

## Parameters

### `bSuccess` [in]

Specify **TRUE** to indicate that the data was successfully recovered; otherwise, **FALSE**.

## Remarks

This should be the last call that you make in your callback because your application terminates as soon as this function is called.

## See also

[ApplicationRecoveryInProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-applicationrecoveryinprogress)

[RegisterApplicationRecoveryCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrecoverycallback)