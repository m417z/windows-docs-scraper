# IWDFIoTargetStateManagement::Remove

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Remove** method removes a [local I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

## Parameters

### `bIsSurpriseRemove` [in]

A BOOL value which, if **TRUE**, specifies that the device was unexpectedly removed ("surprise removal"). However, the framework ignores this parameter.

## Return value

**Remove** always returns S_OK.

## Remarks

Although the **Remove** method is available, drivers do not need to call it. If a driver has called [IWDFFileHandleTargetFactory::CreateFileHandleTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffilehandletargetfactory-createfilehandletarget) to create a file-handle-based I/O target, the driver should call [IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject) to delete the I/O target object after the driver has finished using the file-handle-based target. The **DeleteWdfObject** method performs the operations that **Remove** performs, along with additional operations.

## See also

[IWDFIoTargetStateManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotargetstatemanagement)