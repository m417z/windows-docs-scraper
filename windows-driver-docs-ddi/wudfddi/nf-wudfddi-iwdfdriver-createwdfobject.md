# IWDFDriver::CreateWdfObject

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateWdfObject** method creates a custom (or user) WDF object from a parent WDF object.

## Parameters

### `pCallbackInterface` [in, optional]

A pointer to the **IUnknown** interface that the framework uses to determine the object-related event callback functions that the driver subscribes to on the newly created custom object. This parameter is optional. The driver can pass **NULL** if the driver does not require notification. If the driver passes a valid pointer, the framework will call **QueryInterface** on the **IUnknown** interface for the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface. If the framework obtains the driver's **IObjectCleanup** interface, the framework can subsequently call the driver's [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) method to notify the driver that the custom object is cleaned up.

### `pParentObject` [in, optional]

A pointer to the [IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject) interface for the parent WDF object. If **NULL**, the driver object becomes the default parent.

### `ppWdfObject` [out]

A pointer to a buffer that receives a pointer to the [IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject) interface for the newly created WDF object.

## Return value

**CreateWdfObject** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The driver can call **CreateWdfObject** to create a general [framework base object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-base-object) for its own use. The driver can associate context memory, assign a parent object, and register an [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface. The framework subsequently calls the [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) method to clean up the child object.

If no parent object is specified at the *pParentObject* parameter, the driver becomes the default parent. Therefore, when the driver object is deleted, the framework cleans up the child object.

If a parent object is assigned, the child object is deleted when the parent object is deleted. In other words, the lifetime of a child object is scoped within that of the parent.

If the driver must clean up the child object before the parent object is deleted, the driver can call the [IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject) method.

## See also

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)

[IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject)