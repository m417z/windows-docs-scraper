# GetDoubleClickTime function

## Description

Retrieves the current double-click time for the mouse. A double-click is a series of two clicks of the mouse button, the second occurring within a specified time after the first. The double-click time is the maximum number of milliseconds that may occur between the first and second click of a double-click. The maximum double-click time is 5000 milliseconds.

## Return value

Type: **UINT**

The return value specifies the current double-click time, in milliseconds. The maximum return value is 5000 milliseconds.

## See also

**Conceptual**

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**

[SetDoubleClickTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdoubleclicktime)