# GetCurrentActCtx function

## Description

The
**GetCurrentActCtx** function returns the handle to the active activation context of the calling thread.

## Parameters

### `lphActCtx` [out]

Pointer to the returned
[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa) structure that contains information on the active activation context.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The calling thread is responsible for releasing the handle of the returned activation context. This function can return a null handle if no activation contexts have been activated by this thread. This is not an error.

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)