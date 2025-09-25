# LogTimeProvEventFunc callback function

## Description

Logs a time provider event in the event log.

## Parameters

### `wType` [in]

The event type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **Error** | Indicates a significant problem. |
| **Information** | Provides information about a successful operation. |
| **Warning** | Indicates a problem that is not immediately significant, but may cause future problems. |

### `wszProvName` [in]

The provider name.

### `wszMessage` [in]

The event description.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

This function provides the time provider with a simplified interface for event logging. Time providers that require more extensive event logging can perform their own event logging. For more information on event logging, see
[Event Logging](https://learn.microsoft.com/windows/desktop/EventLog/event-logging).

The
[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen) function returns a pointer to this function.

## See also

[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen)