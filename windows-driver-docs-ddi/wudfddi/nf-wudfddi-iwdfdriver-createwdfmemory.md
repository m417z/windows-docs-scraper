# IWDFDriver::CreateWdfMemory

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateWdfMemory** method creates a [framework memory object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-memory-object) and allocates, for the memory object, a data buffer of the specified nonzero size.

## Parameters

### `BufferSize` [in]

The nonzero specified size, in bytes, of data for the newly created WDF memory object's data buffer.

### `pCallbackInterface` [in, optional]

A pointer to the **IUnknown** interface that the framework uses to determine the object-related event callback functions that the driver subscribes to on the newly created memory object. This parameter is optional. The driver can pass **NULL** if the driver does not require notification. The **IUnknown** interface is used for object cleanup and disposal. If the driver passes a valid pointer, the framework will call **QueryInterface** on the **IUnknown** interface for the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface. If the framework obtains the driver's **IObjectCleanup** interface, the framework can subsequently call the driver's [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) method to notify the driver that the memory object is cleaned up.

### `pParentObject` [in, optional]

A pointer to the [IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject) interface for the parent object of the created memory object. If **NULL**, the driver object becomes the default parent.

### `ppWdfMemory` [out]

A pointer to a buffer that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for the newly created WDF memory object.

## Return value

**CreateWdfMemory** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The **CreateWdfMemory** method allocates a buffer of the size that the *BufferSize* parameter specifies, and creates a framework memory object that represents the buffer.

If **NULL** is specified in the *pParentObject* parameter, the driver object becomes the default parent object for the newly created memory object. If a UMDF driver creates a memory object that the driver uses with a specific device object, request object, or other framework object, the driver should set the memory object's parent object appropriately. When the parent object is deleted, the memory object and its buffer are deleted.

A UMDF driver can also delete a memory object and its buffer by calling [IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject).

A UMDF driver cannot create a memory object with a zero-specified size buffer. If a driver must use a zero-specified size buffer, the driver should use a **NULL** memory object instead. For example, if the driver must use a zero-specified size buffer in a read request, the driver must pass **NULL** to the *pOutputMemory* parameter in a call to the [IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread) method.

#### Examples

The following code example shows how to create a memory object that can hold information that is read from a USB endpoint.

```
HRESULT
CUmdfHidDevice::PrepareReader(
    VOID
    )
{
    CComPtr<IWDFDevice> wdfDevice;
    CComPtr<IWDFDriver> wdfDriver;
    CComPtr<IWDFIoRequest> wdfRequest;

    HRESULT hr;

    GetWdfDevice(&wdfDevice);
    wdfDevice->GetDriver(&wdfDriver);

    // Open the interrupt pipe.
    hr = m_HidInterface->RetrieveUsbPipeObject(
                         USB_HID_INTERRUPT_PIPE_INDEX,
                         &m_InterruptPipe
                         );

    // Allocate a memory object to hold information that
    // is read from the interrupt pipe.
    // This memory object will be reused.
    if (SUCCEEDED(hr))
    {
        hr = wdfDriver->CreateWdfMemory(m_ReadBufferSize,
                                        NULL,
                                        wdfDevice,
                                        &m_ReadMemory);
    }

    return hr;
}
```

## See also

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)

[IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)

[IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject)