# IObjectCleanup::OnCleanup

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnCleanup** method releases any references to a WDF object to prevent interface leakage.

## Parameters

### `pWdfObject` [in]

A pointer to the [IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject) interface of an object that is about to be released.

## Remarks

The framework calls **OnCleanup** as part of a WDF object destruction sequence. The framework calls **OnCleanup** before the WDF object is destroyed.

A driver can register the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface when the driver calls any of the following methods that creates a WDF object or that assigns a context to the WDF object:

* [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)
* [IWDFDevice::CreateRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createrequest)
* [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)
* [IWDFDriver::CreatePreallocatedWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createpreallocatedwdfmemory)
* [IWDFDriver::CreateWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createwdfmemory)
* [IWDFDriver::CreateWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createwdfobject)
* [IWDFObject::AssignContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext)

## See also

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)

[IWDFDevice::CreateRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createrequest)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)

[IWDFDriver::CreatePreallocatedWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createpreallocatedwdfmemory)

[IWDFDriver::CreateWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createwdfmemory)

[IWDFDriver::CreateWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createwdfobject)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)

[IWDFObject::AssignContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext)