# IWDFDriver::CreatePreallocatedWdfMemory

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreatePreallocatedWdfMemory** method creates a [framework memory object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-memory-object) for the specified buffer.

## Parameters

### `pBuff` [in]

A pointer to a driver-supplied data buffer for the memory object.

### `BufferSize` [in]

The size, in bytes, of data that *pBuff* points to.

### `pCallbackInterface` [in, optional]

A pointer to the **IUnknown** interface that the framework uses to determine the object-related event callback functions that the driver subscribes to on the newly created memory object. This parameter is optional. The driver can pass **NULL** if the driver does not require notification. The **IUnknown** interface is used for object cleanup and disposal. If the driver passes a valid pointer, the framework will call **QueryInterface** on the **IUnknown** interface for the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface. If the framework obtains the driver's **IObjectCleanup** interface, the framework can subsequently call the driver's [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) method to notify the driver that the memory object is cleaned up.

### `pParentObject` [in, optional]

A pointer to the [IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject) interface for the parent object of the created memory object. If **NULL**, the driver object becomes the default parent.

### `ppWdfMemory` [out]

A pointer to a buffer that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for the newly created WDF memory object.

## Return value

**CreatePreallocatedWdfMemory** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The **CreatePreallocatedWdfMemory** method creates a framework memory object for a buffer that the driver previously allocated or obtained.

A UMDF driver can call **CreatePreallocatedWdfMemory** if it must create a memory object that represents a pre-existing memory buffer. For example, the driver might receive a driver-defined structure within a buffer for an I/O request that contains an internal I/O control code. The driver can call **CreatePreallocatedWdfMemory** to create a memory object so that the driver can pass the structure to an I/O target.

After a UMDF driver calls **CreatePreallocatedWdfMemory**, the driver can call [IWDFMemory::SetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-setbuffer) to assign a different buffer to the memory object that **CreatePreallocatedWdfMemory** created.

When the framework memory object that **CreatePreallocatedWdfMemory** created is deleted, the framework does not deallocate the pre-existing buffer. Likewise, a call to [IWDFMemory::SetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-setbuffer) does not deallocate the previously assigned buffer.

#### Examples

The following code example shows how to create a memory object for a buffer.

```
    //
    // Allocate a request.
    hr = wdfDevice->CreateRequest(NULL, NULL, &request);

    // Allocate a buffer and wrap it in a memory object.
    // Make the memory object a child of the request.
    // When the request object is deleted, the memory object
    // is also deleted.

    if (SUCCEEDED(hr))
    {
       buffer = new BYTE[m_HidDescriptor->wReportLength];

       if (buffer == NULL)
       {
          hr = E_OUTOFMEMORY;
       }
    }

    if (SUCCEEDED(hr))
    {
       CComPtr<IWDFDriver> driver;
       wdfDevice->GetDriver(&driver);

       hr = driver->CreatePreallocatedWdfMemory(
                       buffer,
                       m_HidDescriptor->wReportLength,
                       NULL,
                       request,
                       &memory
                       );
    }
```

## See also

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)

[IWDFMemory::SetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-setbuffer)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)