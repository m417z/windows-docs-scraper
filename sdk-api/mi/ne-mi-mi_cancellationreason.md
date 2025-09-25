# MI_CancellationReason enumeration

## Description

Value to pass to an operation cancel request to notify the system of the reason the operation is being canceled. If the service is being shutdown, it may pass one of these values to the provider as well.

## Constants

### `MI_REASON_NONE`

No reason for cancellation.

### `MI_REASON_TIMEOUT`

Operation timed out.

### `MI_REASON_SHUTDOWN`

The system is being shutdown.

### `MI_REASON_SERVICESTOP`

The service is being stopped.

## See also

[MI_CancelCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792316(v=vs.85))