# WdfRequestGetStatus function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetStatus** method returns the status of an I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetStatus** returns an NTSTATUS value. For more information about what value can be returned, see the following Remarks section.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfRequestGetStatus** method returns one of the following:

* If a driver's call to [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) succeeds, **WdfRequestGetStatus** returns the status value that is set by the driver that calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete the specified request. The driver typically calls **WdfRequestGetStatus** from within a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function.
* If a driver's call to [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) fails, **WdfRequestGetStatus** returns a status value that the framework has set to describe the failure. The driver can call **WdfRequestGetStatus** immediately after calling **WdfRequestSend**.

If the driver sets the [WDF_REQUEST_SEND_OPTION_SYNCHRONOUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags) flag for a request when calling [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), the driver can call **WdfRequestGetStatus** immediately after calling **WdfRequestSend**, whether the call to **WdfRequestSend** succeeds or fails.

For more information about request completion, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example is from the [KbFiltr](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example sends an I/O request to an I/O target. If [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) fails, the example uses the **WdfRequestGetStatus** return value as input to [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete).

```cpp
VOID
KbFilter_ForwardRequest(
    IN WDFREQUEST Request,
    IN WDFIOTARGET Target
    )
{
    WDF_REQUEST_SEND_OPTIONS options;
    BOOLEAN ret;
    NTSTATUS status;

    WDF_REQUEST_SEND_OPTIONS_INIT(
                                  &options,
                                  WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET
                                  );

    ret = WdfRequestSend(
                         Request,
                         Target,
                         &options
                         );

    if (ret == FALSE) {
        status = WdfRequestGetStatus (Request);
        DebugPrint(("WdfRequestSend failed: 0x%x\n", status));
        WdfRequestComplete(
                           Request,
                           status
                           );
    }
    return;
}
```

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)