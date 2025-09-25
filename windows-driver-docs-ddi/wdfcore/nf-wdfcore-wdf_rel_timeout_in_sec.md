# WDF_REL_TIMEOUT_IN_SEC function

## Description

[Applies to KMDF and UMDF]

The **WDF_REL_TIMEOUT_IN_SEC** function converts a specified number of seconds to a relative time value.

## Parameters

### `Time` [in]

The number of seconds to convert.

## Return value

**WDF_REL_TIMEOUT_IN_SEC** returns the relative time value, in system time units (100-nanosecond intervals), that represents the number of seconds that *Time* specifies.

## Remarks

A relative time is a time value that is relative to the current system time. For example, if a caller passes a relative time value of five seconds to a function that accepts a time-out value, the function will time out five seconds after it is called.

#### Examples

The following code example specifies a relative timeout value of 5 seconds for an I/O request.

```cpp
WDF_REQUEST_SEND_OPTIONS  requestSendOptions;
...
requestSendOptions.Timeout = WDF_REL_TIMEOUT_IN_SEC(5);
...
```

## See also

[WDF_ABS_TIMEOUT_IN_SEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_abs_timeout_in_sec)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)