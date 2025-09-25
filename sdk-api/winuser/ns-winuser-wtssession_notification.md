# WTSSESSION_NOTIFICATION structure

## Description

Provides information about the session change notification. A service receives this structure in its
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) function in response to a session change event.

## Members

### `cbSize`

Size, in bytes, of this structure.

### `dwSessionId`

Session identifier that triggered the session change event.

## See also

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)