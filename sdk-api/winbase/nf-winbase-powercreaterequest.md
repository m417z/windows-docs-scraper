# PowerCreateRequest function

## Description

Creates a new power request object.

## Parameters

### `Context` [in]

Points to a [REASON_CONTEXT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-reason_context) structure that contains information about the power request.

## Return value

If the function succeeds, the return value is a handle to the power request object.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When the power request object is no longer needed, use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to free the handle and clean up the object.

## See also

[PowerClearRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powerclearrequest)

[PowerSetRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powersetrequest)