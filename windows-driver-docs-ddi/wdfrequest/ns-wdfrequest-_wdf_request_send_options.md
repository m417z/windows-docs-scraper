# _WDF_REQUEST_SEND_OPTIONS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_SEND_OPTIONS** structure specifies options that are associated with sending an I/O request to an I/O target.

## Members

### `Size`

The size, in bytes, of this structure.

### `Flags`

A bitwise OR of [WDF_REQUEST_SEND_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags)-typed flags.

### `Timeout`

A time-out value, in system time units (100-nanosecond intervals). If the driver has set the WDF_REQUEST_SEND_OPTION_TIMEOUT flag, the framework cancels the associated I/O request if it is not completed within the specified time-out period. The time-out value can be negative, positive, or zero, as follows:

* If the value is negative, the expiration time is relative to the current system time.
* If the value is positive, the expiration time is specified as an absolute time (which is actually relative to January 1, 1601).
* If the value is zero, the framework does not time out the request.

Relative expiration times are not affected by any changes to the system time that might occur within the specified time-out period. Absolute expiration times do reflect system time changes.

The framework provides [time conversion functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/) that convert time values into system time units.

If the framework cancels an I/O request because the specified time-out period has elapsed, the framework provides a completion status of STATUS_IO_TIMEOUT for the I/O request. However, after the time-out period elapses, the I/O target might complete the I/O request before the framework is able to cancel it. In that case, the I/O request's completion status will not be STATUS_IO_TIMEOUT.

## Remarks

The **WDF_REQUEST_SEND_OPTIONS** structure is passed to object methods that send an I/O request to an I/O target, such as the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method. The structure must be initialized by calling the [WDF_REQUEST_SEND_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_init) and [WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_set_timeout) functions.

If the driver is sending the request synchronously, we recommend that the driver set a time-out value and the time-out flag in the **Flags** member of this structure.

## See also

[WDF_REQUEST_SEND_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags)

[WDF_REQUEST_SEND_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_init)

[WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_set_timeout)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)