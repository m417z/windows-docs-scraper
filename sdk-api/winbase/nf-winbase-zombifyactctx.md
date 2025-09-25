# ZombifyActCtx function

## Description

The
**ZombifyActCtx** function deactivates the specified activation context, but does not deallocate it.

## Parameters

### `hActCtx` [in]

Handle to the activation context that is to be deactivated.

## Return value

If the function succeeds, it returns **TRUE**. If a **null** handle is passed in the *hActCtx* parameter, NULL_INVALID_PARAMETER will be returned. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function is intended for use in debugging threads using activation contexts. If the activation context deactivated by this function is subsequently accessed, the access fails and an assertion failure is shown in the debugger.

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)