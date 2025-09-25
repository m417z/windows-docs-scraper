# SetDoubleClickTime function

## Description

Sets the double-click time for the mouse. A double-click is a series of two clicks of a mouse button, the second occurring within a specified time after the first. The double-click time is the maximum number of milliseconds that may occur between the first and second clicks of a double-click.

## Parameters

### `unnamedParam1` [in]

Type: **UINT**

The number of milliseconds that may occur between the first and second clicks of a double-click. If this parameter is set to 0, the system uses the default double-click time of 500 milliseconds. If this parameter value is greater than 5000 milliseconds, the system sets the value to 5000 milliseconds.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetDoubleClickTime** function alters the double-click time for all windows in the system.

## See also

**Conceptual**

[GetDoubleClickTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdoubleclicktime)

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**