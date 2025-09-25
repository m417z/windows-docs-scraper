# ID3D10Device::SetExceptionMode

## Description

Get the exception-mode flags.

## Parameters

### `RaiseFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that contains one or more exception flags; each flag specifies a condition which will cause an exception to be raised. The flags are listed in [D3D10_RAISE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_raise_flag). A default value of 0 means there are no flags.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Set an exception-mode flag to elevate an error condition to a non-continuable exception.

Whenever an error occurs, a Direct3D device enters the DEVICEREMOVED state and if the appropriate exception flag has been set, an exception is raised. A raised exception is designed to terminate an application. Before termination, the last chance an application has to persist data is by using an UnhandledExceptionFilter (see [Structured Exception Handling](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling)). In general, UnhandledExceptionFilters are leveraged to try to persist data when an application is crashing (to disk, for example). Any code that executes during an UnhandledExceptionFilter is not guaranteed to reliably execute (due to possible process corruption). Any data that the UnhandledExceptionFilter manages to persist, before the UnhandledExceptionFilter crashes again, should be treated as suspect, and therefore inspected by a new, non-corrupted process to see if it is usable.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)