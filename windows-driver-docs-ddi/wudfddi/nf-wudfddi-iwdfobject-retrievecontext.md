# IWDFObject::RetrieveContext

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveContext** method retrieves a context that was previously registered through the [IWDFObject::AssignContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext) method.

## Parameters

### `ppvContext` [out]

A pointer to a buffer that receives a pointer to the previously registered context.

## Return value

**RetrieveContext** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Because the context is not a Component Object Model (COM) interface, the driver must not treat the context as such. For example, the driver cannot call the **AddRef** method on the context.

#### Examples

For a code example of how to use the **RetrieveContext** method, see [IWDFIoQueue::GetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-getdevice).

## See also

[IWDFIoQueue::GetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-getdevice)

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)

[IWDFObject::AssignContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext)