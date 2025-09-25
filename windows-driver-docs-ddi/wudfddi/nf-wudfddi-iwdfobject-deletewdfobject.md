# IWDFObject::DeleteWdfObject

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **DeleteWdfObject** method deletes a previously created Microsoft Windows Driver Frameworks (WDF) object.

## Return value

**DeleteWdfObject** returns S_OK if the operation succeeds. Otherwise, this method returns HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED) or one of the other error codes that are defined in Winerror.h.

## Remarks

A driver is unable to delete some WDF objects. For example, the driver cannot delete a [framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object) because the framework owns and controls device objects. For more information about the hierarchy of WDF objects, see [Framework Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-hierarchy).

The driver typically deletes only WDF objects that it creates and owns. For more information about deleting framework objects, see [Managing the Lifetime of Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-the-lifetime-of-objects).

However, when a parent object is deleted, all child objects are automatically deleted. For example, if the driver called [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue) to create an I/O queue object, the newly created I/O queue becomes a child of the device object. The I/O queue object is then automatically deleted when the device object is deleted without the driver explicitly calling **DeleteWdfObject**.

#### Examples

For a code example of how to use the **DeleteWdfObject** method, see [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate).

## See also

[IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)