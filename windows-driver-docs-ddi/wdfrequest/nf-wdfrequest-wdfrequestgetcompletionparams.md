# WdfRequestGetCompletionParams function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetCompletionParams** method retrieves the I/O completion parameters that are associated with a specified framework request object.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Params` [in, out]

A pointer to a caller-supplied [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver has called [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to synchronously or asynchronously send an I/O request to an I/O target, and after the I/O target has [completed](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) the I/O request, the driver can call **WdfRequestGetCompletionParams** to obtain the I/O request's completion parameters.

The completion parameters structure contains valid information only if the driver has formatted the request by calling one of the **WdfIoTargetFormat***Xxx* methods. For example, see [WdfIoTargetFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforread).

Note that if your driver calls one of the methods that sends I/O requests to I/O targets only synchronously (such as [WdfIoTargetSendReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendreadsynchronously)), the driver must *not* call **WdfRequestGetCompletionParams**.

The **WdfRequestGetCompletionParams** method copies the I/O request's completion parameters into the specified [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure.

If a driver sends an I/O request asynchronously, it typically calls this method from within a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function.

For more information about **WdfRequestGetCompletionParams**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example initializes a [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure and then calls **WdfRequestGetCompletionParams**.

```cpp
WDF_REQUEST_COMPLETION_PARAMS completionParams;

WDF_REQUEST_COMPLETION_PARAMS_INIT(&completionParams);
WdfRequestGetCompletionParams(
                              request,
                              &completionParams
                              );
```

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params)

[WDF_REQUEST_COMPLETION_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_completion_params_init)