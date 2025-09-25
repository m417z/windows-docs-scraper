# IWDFIoRequest::Send

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Send** method sends a request to the specified I/O target.

## Parameters

### `pIoTarget` [in]

A pointer to the [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget) interface for the I/O target object, which typically represents a lower driver in the stack.

### `Flags` [in]

A valid bitwise OR of [WDF_REQUEST_SEND_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags)-typed flags.

### `Timeout` [in]

The amount of time, in system time units (100-nanosecond intervals), that can elapse before the framework automatically cancels the I/O request.

* If the value is negative, the expiration time is relative to the current system time.
* If the value is positive, the expiration time is specified as an absolute time (which is relative to January 1, 1601).
* If the value is zero, the framework does not time out the request.

Relative expiration times are not affected by any changes to the system time that might occur within the specified time-out period. Absolute expiration times reflect system time changes.

## Return value

**Send** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

Note that the return value represents the status of the **Send** method's attempt to send the I/O request to the I/O target. The return value does not represent the completion status of the I/O request. Your driver must use the [IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams) interface to obtain the I/O request's completion status.

## Remarks

If **Send** returns an error code, the driver should typically complete the request with the error code that **Send** returned, as the code in the following Example section shows.

If your driver sets the WDF_REQUEST_SEND_OPTION_SYNCHRONOUS flag in the *Flags* parameter, and if **Send** successfully sends the I/O request to the I/O target, **Send** returns after the I/O target completes the I/O request. In this case, **Send** returns S_OK and the driver can immediately call [IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams) to obtain the [IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams) interface. The code example at **IWDFIoRequest::GetCompletionParams** shows a call to **Send** with the WDF_REQUEST_SEND_OPTION_SYNCHRONOUS flag set.

If your driver does not set the WDF_REQUEST_SEND_OPTION_SYNCHRONOUS flag, and if **Send** successfully sends the I/O request to the I/O target, **Send** returns S_OK while the I/O target is still processing the I/O request asynchronously. In this case, the driver provides an [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function that the framework calls after the I/O target completes the I/O request. Typically, the **OnCompletion** callback function calls [IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams). The code example in the following Example section shows a call to **Send** without the WDF_REQUEST_SEND_OPTION_SYNCHRONOUS flag.

A driver cannot call **Send** to send an I/O request to a USB pipe, if the driver has configured a [continuous reader](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes-in-umdf-1-x-drivers) for the pipe.

#### Examples

The following code example forwards a request to a device's I/O target.

```
    IWDFIoRequest* FxRequest;

    //
    // Set the completion callback.
    // When the lower request is completed, the driver is
    // notified through the completion callback.
    //

    IRequestCallbackRequestCompletion *completionCallback =
        QueryIRequestCallbackRequestCompletion();

    FxRequest->SetCompletionCallback(
                                     completionCallback,
                                     NULL  //pContext
                                     );

    completionCallback->Release();

    //
    // Format the I/O request.

    FxRequest->FormatUsingCurrentType( );

    //
    // Send down the request.
    //
    HRESULT hrSend = S_OK;

    hrSend = FxRequest->Send(
                             m_FxIoTarget,
                             0, // Asynchronous
                             0  // No time-out
                             );

    if (S_OK != hrSend) {
        //
        // If the send failed, the driver must complete the
        // request with the failure.
        FxRequest->CompleteWithInformation(hrSend, 0);
    }
```

## See also

[IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams)

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)

[WDF_REQUEST_SEND_OPTIONS_FLAGS (UMDF)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_request_send_options_flags)