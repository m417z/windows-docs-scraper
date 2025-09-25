# CreateActCtxA function

## Description

The
**CreateActCtx** function creates an activation context.

## Parameters

### `pActCtx` [in, out]

Pointer to an
[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa) structure that contains information about the activation context to be created.

## Return value

If the function succeeds, it returns a handle to the returned activation context. Otherwise, it returns INVALID_HANDLE_VALUE.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Set any undefined bits in **dwFlags** of
[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa) to 0. If any undefined bits are not set to 0, the call to
**CreateActCtx** that creates the activation context fails and returns an invalid parameter error code. The handle returned from
**CreateActCtx** is passed in a call to
[ActivateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-activateactctx) to activate the context for the current thread.

> [!NOTE]
> The winbase.h header defines CreateActCtx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)