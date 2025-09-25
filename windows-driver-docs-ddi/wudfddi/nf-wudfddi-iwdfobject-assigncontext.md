# IWDFObject::AssignContext

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AssignContext** method registers a context and a driver-supplied cleanup callback function for the object.

## Parameters

### `pCleanupCallback` [in, optional]

A pointer to the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface that contains the cleanup callback function, which performs cleanup operations for the object if it becomes invalid. This parameter is optional. The driver can pass **NULL** if the driver does not require notification when the object is cleaned up.

### `pContext` [in, optional]

A pointer to the context to register. **NULL** is a valid context.

## Return value

**AssignContext** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

A driver calls **AssignContext** to register a context and to request notification when the object becomes invalid. In an **AssignContext** call, the driver passes a pointer to the [IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup) interface in the *pCleanupCallback* parameter to register **IObjectCleanup**. Note that the framework internally holds a reference to the supplied **IObjectCleanup** interface while the object is valid. When the object becomes invalid, the framework calls the [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) method to notify the driver. The framework automatically releases the reference to the supplied **IObjectCleanup** after calling **IObjectCleanup::OnCleanup**.

At any given time, only one context that is associated with each object instance can exist. Attempts to register additional contexts fail.

A context can be associated only with an object that is in a valid state. For example, an attempt to associate a context with an object that is in the process of deletion fails.

Because the context is not a Component Object Model (COM) interface, the driver must not treat the context as such. For example, the driver cannot call the **AddRef** method on the context.

The [IWDFObject::RetrieveContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-retrievecontext) method can be used to retrieve the context that was previously registered through **AssignContext**.

#### Examples

For a code example of how to use the **AssignContext** method, see [IWDFIoTarget::FormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforwrite).

## See also

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)

[IWDFObject::RetrieveContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-retrievecontext)