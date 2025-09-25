# IWDFIoRequest2::GetStatus

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetStatus** method returns the status of an I/O request.

## Return value

**GetStatus** returns an HRESULT-typed status value, This value indicates the current status of the I/O request that the [IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2) interface represents.

## Remarks

A driver can call **GetStatus** after it has called [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) to send an I/O request to an I/O target.

* If a driver's call to [Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) succeeds, **GetStatus** returns the status value that is set by the driver that completes the specified request.

  If the driver specifies WDF_REQUEST_SEND_OPTION_SYNCHRONOUS for a request when it calls [Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send), the driver can call **GetStatus** (or [IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams)) immediately after calling **Send**.

  If the driver does not specify WDF_REQUEST_SEND_OPTION_SYNCHRONOUS when it calls [Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send), the driver typically calls **GetStatus** (or [IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams)) from within an [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function.
* If a driver's call to [Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) fails, **Send** returns a status value that the framework has set to describe the failure. The driver can call **GetStatus** (but not[IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams)) to obtain the current status of the request, but in this case **GetStatus** returns the same failure code that **Send** returned.

For more information about request completion, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example sends an I/O request to an I/O target. If the call to [Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) succeeds, the example obtains the [IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2) interface, calls **GetStatus** to obtain the request's status value, and then calls [IWDFIoRequest::CompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-completewithinformation) to complete the I/O request.

```
HRESULT hrSend = S_OK;
...
hrSend = fxRequest->Send(m_pIoTarget,
                         WDF_REQUEST_SEND_OPTION_SYNCHRONOUS,
                         0);
if (SUCCEEDED(hrSend))
{
    //
    // If send succeeded, complete the request and specify
    // the current status value.
    //
    CComQIPtr<IWDFIoRequest2> fxRequest2 = fxRequest;
    hrSend = fxRequest2->GetStatus();
    fxRequest->CompleteWithInformation(hrSend, 0);
}
...
```

## See also

[IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion)

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest::CompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-completewithinformation)

[IWDFIoRequest::GetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcompletionparams)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)