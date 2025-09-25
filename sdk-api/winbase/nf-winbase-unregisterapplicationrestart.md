# UnregisterApplicationRestart function

## Description

Removes the active instance of an application from the restart list.

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Internal error. |

## Remarks

You do not need to call this function before exiting. You need to remove the registration only if you choose to not restart the application. For example, you could remove the registration if your application entered a corrupted state where a future restart would also fail. You must call this function before the application fails abnormally.

## See also

[RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart)