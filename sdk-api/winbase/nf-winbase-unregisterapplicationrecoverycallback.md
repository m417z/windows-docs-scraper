# UnregisterApplicationRecoveryCallback function

## Description

Removes the active instance of an application from the recovery list.

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Internal error. |

## Remarks

You do not need to call this function before exiting. You need to remove the registration only if you choose to not recover data.

## See also

[RegisterApplicationRecoveryCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrecoverycallback)