# DeactivateActCtx function

## Description

The
**DeactivateActCtx** function deactivates the activation context corresponding to the specified cookie.

## Parameters

### `dwFlags` [in]

Flags that indicate how the deactivation is to occur.

| Value | Meaning |
| --- | --- |
| **0** | If this value is set and the cookie specified in the *ulCookie* parameter is in the top frame of the activation stack, the activation context is popped from the stack and thereby deactivated. <br><br>If this value is set and the cookie specified in the *ulCookie* parameter is not in the top frame of the activation stack, this function searches down the stack for the cookie.<br><br>If the cookie is found, a STATUS_SXS_EARLY_DEACTIVATION exception is thrown.<br><br>If the cookie is not found, a STATUS_SXS_INVALID_DEACTIVATION exception is thrown.<br><br>This value should be specified in most cases. |
| **DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION** | If this value is set and the cookie specified in the *ulCookie* parameter is in the top frame of the activation stack, the function returns an ERROR_INVALID_PARAMETER error code. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain this code. <br><br>If this value is set and the cookie is not on the activation stack, a STATUS_SXS_INVALID_DEACTIVATION exception will be thrown.<br><br>If this value is set and the cookie is in a lower frame of the activation stack, all of the frames down to and including the frame the cookie is in is popped from the stack. |

### `ulCookie` [in]

The ULONG_PTR that was passed into the call to
[ActivateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-activateactctx). This value is used as a cookie to identify a specific activated activation context.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The deactivation of activation contexts must occur in the reverse order of activation. It can be understood as popping an activation context from a stack.

## See also

[ActivateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-activateactctx)