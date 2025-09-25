# ActivateActCtx function

## Description

The
**ActivateActCtx** function activates the specified activation context. It does this by pushing the specified activation context to the top of the activation stack. The specified activation context is thus associated with the current thread and any appropriate side-by-side API functions.

## Parameters

### `hActCtx` [in]

Handle to an
[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa) structure that contains information on the activation context that is to be made active.

### `lpCookie` [out]

Pointer to a **ULONG_PTR** that functions as a cookie, uniquely identifying a specific, activated activation context.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The *lpCookie* parameter is later passed to
[DeactivateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deactivateactctx), which verifies the pairing of calls to
**ActivateActCtx** and
**DeactivateActCtx** and ensures that the appropriate activation context is being deactivated. This is done because the deactivation of activation contexts must occur in the reverse order of activation.

The activation of activation contexts can be understood as pushing an activation context onto a stack of activation contexts. The activation context you activate through this function redirects any binding to DLLs, window classes, COM servers, type libraries, and mutexes for any side-by-side APIs you call.

The top item of an activation context stack is the active, default-activation context of the current thread. If a null activation context handle is pushed onto the stack, thereby activating it, the default settings in the original manifest override all activation contexts that are lower on the stack.

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)

[DeactivateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deactivateactctx)