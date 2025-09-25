# IWDFIoRequest2::Reuse

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Reuse** method reinitializes a framework request object so that it can be reused.

## Parameters

### `hrNewStatus` [in]

An HRESULT-typed status value that the framework assigns to the request.

## Remarks

If a framework-based driver calls [IWDFDevice::CreateRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createrequest) to create request objects, the driver can reuse those request objects. Drivers can also reuse request objects that they receive from the framework in their I/O queues.

A driver can reuse a request object after the original request has been completed. After a driver has called **Reuse**, the request's contents must be reinitialized.

If you want the reused request to have an [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function, the driver must call [IWDFIoRequest::SetCompletionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setcompletioncallback) after it calls **Reuse**.

For more information about **Reuse**, see [Reusing Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/reusing-framework-request-objects).

#### Examples

The following code example shows how an [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function can obtain the [IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2) interface and then call **Reuse**.

```
void
STDMETHODCALLTYPE
CMyRemoteDevice::OnCompletion(
    __in IWDFIoRequest*  FxRequest,
    __in IWDFIoTarget*  FxTarget,
    __in IWDFRequestCompletionParams*  Params,
    __in void*  Context
    )
{
...
    CComQIPtr<IWDFIoRequest2> fxRequest2(FxRequest);
    fxRequest2->Reuse(S_OK);
...
}
```

## See also

[IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion)

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest::SetCompletionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setcompletioncallback)