# IQueueCallbackCreate::OnCreateFile

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **OnCreateFile** method is called to handle an open file request when an application opens a device through the Microsoft Win32 **CreateFile** function.

## Parameters

### `pWdfQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue object form which the request arrives.

### `pWDFRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the I/O request object for the device.

### `pWdfFileObject` [in]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object that is associated with the device. This information is provided for convenience because the driver can call the [IWDFIoRequest::GetCreateParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcreateparameters) method to obtain the file object.

## Remarks

If the driver implements the [IQueueCallbackCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackcreate) interface, the framework calls the **OnCreateFile** method when an application opens a device through the Win32 **CreateFile** function to perform an I/O operation, such as reading from or writing to a file.

A driver registers the [IQueueCallbackCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackcreate) interface when the driver calls the [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue) method to create an I/O queue or to configure the default I/O queue.

A typical **OnCreateFile** method might call [IWDFObject::AssignContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext) method on the file object to associate context with the file object, and then call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) to complete the request.

A UMDF driver might be required to open registry keys or files while it impersonates a client that sends the I/O requests. From its implementation of the **OnCreateFile** method, the driver calls the [IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate) method to set a security impersonation level and to set the [IImpersonateCallback::OnImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iimpersonatecallback-onimpersonate) method in which the driver handles the impersonation. To access necessary resources by using the credentials of the user, the framework calls the driver's **OnImpersonate** method. For any operations other than those that require impersonation, the framework calls driver methods that run under the default driver account. For more information about how UMDF and UMDF drivers handle impersonation, see [Handling Impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

### Examples

This example is based on the WpdWudfSampleDriver sample, and is from the Queue.cpp file.

```cpp
STDMETHODIMP_ (void) CQueue::OnCreateFile(
/*[in]*/ IWDFIoQueue* pQueue,
/*[in]*/ IWDFIoRequest* pRequest,
/*[in]*/ IWDFFile* pFileObject
)
{
  HRESULT hr = S_OK;
  ClientContext* pClientContext = new ClientContext ();

  // . . . Code omitted.

  if(pClientContext != NULL) {
    hr = pFileObject->AssignContext (this, (void*)pClientContext);

    // Release the client context if we cannot set it

    if(FAILED(hr)) {
      pClientContext->Release();
      pClientContext = NULL;
    }
  }
  else {
    hr = E_OUTOFMEMORY;
  }

  pRequest->Complete(hr);
}
```

## See also

- [IImpersonateCallback::OnImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iimpersonatecallback-onimpersonate)
- [IQueueCallbackCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackcreate)
- [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)
- [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)
- [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)
- [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)
- [IWDFIoRequest::GetCreateParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcreateparameters)
- [IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate)