## Description

Serves as the entry point for a Control Panel application. This is a library-defined callback function.

## Parameters

### `hwndCpl`

Type: **HWND**

The identifier of the main window of the controlling application. Use the *hwndCPl* parameter for dialog boxes or other windows that require a handle to a parent window.

### `msg`

Type: **UINT**

The message being sent to the Control Panel application.

### `lParam1`

Type: **LPARAM**

Additional message-specific information.

### `lParam2`

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LONG**

The return value depends on the message.

For more information, see the descriptions of the individual [Control Panel messages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc144185(v=vs.85)).

## Remarks

Implementers of Control Panel items must also implement this function. No default implementation is available.