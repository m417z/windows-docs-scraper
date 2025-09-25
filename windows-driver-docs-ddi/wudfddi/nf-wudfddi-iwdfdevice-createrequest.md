# IWDFDevice::CreateRequest

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateRequest** method creates an unformatted request object.

## Parameters

### `pCallbackInterface` [in, optional]

A pointer to the **IUnknown** interface that the framework uses to determine the object-related event callback functions that the driver subscribes to on the newly created request object. This parameter is optional. The driver can pass **NULL** if the driver does not require notification. If the driver passes a valid pointer, the framework will call **QueryInterface** on the **IUnknown** interface for the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface. If the framework obtains the driver's **IObjectCleanup** interface, the framework can subsequently call the driver's [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) method to notify the driver that the request object is cleaned up.

### `pParentObject` [in, optional]

A pointer to the [IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject) interface for the parent object of the created I/O request object. If **NULL**, the device object becomes the default parent.

### `ppRequest` [out]

A pointer to a variable that receives a pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the new request object.

## Return value

**CreateRequest** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Before a UMDF driver uses the request object that **CreateRequest** creates, the driver must format the request object. To format an I/O request object, the driver calls one of the following methods:

* [IWDFIoTarget::FormatRequestForIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforioctl)
* [IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread)
* [IWDFIoTarget::FormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforwrite)

If a driver calls **CreateRequest** to create a request object, it must not call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) for the request object. Instead, the driver must call [IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject) when it has finished using the request object. For more information, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

If **NULL** is specified in the *pParentObject* parameter, the device object becomes the default parent object for the newly created I/O request object. If a UMDF driver creates an I/O request object that the driver uses with a specific I/O queue object or another I/O request object, the driver should set that queue or request object as the created request object's parent object. When the parent object is deleted, the created request object is deleted.

#### Examples

The following code example shows how to create a request, format the request for reading, and send the request on.

```
HRESULT
CUmdfHidDevice::SendInterruptPipeRead(
    VOID
    )
{
    CComPtr<IWDFDevice> wdfDevice;

    HRESULT hr;

    IWDFFile *pTargetFile = NULL;

    // Allocate a new WDF request to send on the interrupt pipe.
    GetWdfDevice(&wdfDevice);
    hr = wdfDevice->CreateRequest(
                                  static_cast<IObjectCleanup*>(this),
                                  wdfDevice,
                                  &m_InterruptReadRequest
                                  );

    if (SUCCEEDED(hr))
    {
        m_InterruptPipe->GetTargetFile(&pTargetFile);
        hr = m_InterruptPipe->FormatRequestForRead(
                                                   m_InterruptReadRequest,
                                                   pTargetFile,
                                                   m_ReadMemory,
                                                   NULL,
                                                   NULL
                                                   );
    }

    // Issue the read to the pipe.
    if (SUCCEEDED(hr))
    {
        hr = m_InterruptReadRequest->Send(m_InterruptPipe, 0, 0);
    }

    return hr;
}
```

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoTarget::FormatRequestForIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforioctl)

[IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread)

[IWDFIoTarget::FormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforwrite)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)