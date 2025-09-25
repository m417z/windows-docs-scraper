# WdfRequestAllocateTimer function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestAllocateTimer** method allocates a timer for a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestAllocateTimer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | A timer could not be allocated. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your driver specifies a time-out value when calling [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), it should call **WdfRequestAllocateTimer** before calling **WdfRequestSend**. This ensures that the call to **WdfRequestSend** will not fail if there are insufficient system resources to allocate a timer.

If a timer is already allocated for the specified request, **WdfRequestAllocateTimer** returns STATUS_SUCCESS.

#### Examples

The following code example initializes a [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, allocates a timer object for the I/O request, and then calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

```cpp
NTSTATUS  status;
WDF_REQUEST_SEND_OPTIONS  options;
BOOLEAN  requestSend;

WDF_REQUEST_SEND_OPTIONS_INIT(
                              &options,
                              WDF_REQUEST_SEND_OPTION_TIMEOUT
                              );

WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(
                                     &options,
                                     WDF_ABS_TIMEOUT_IN_SEC(TIME_OUT_VALUE)
                                     );
status = WdfRequestAllocateTimer(
                                 request
                                 );
if (!NT_SUCCESS(status)){
    return status;
...
    requestSend = WdfRequestSend(
                                 request,
                                 ioTarget,
                                 &options
                                 );
}
```

## See also

[WDF_ABS_TIMEOUT_IN_SEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_abs_timeout_in_sec)

[WDF_REQUEST_SEND_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_init)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)