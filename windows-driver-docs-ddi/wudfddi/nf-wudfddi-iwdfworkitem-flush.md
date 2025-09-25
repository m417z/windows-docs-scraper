# IWDFWorkItem::Flush

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Flush** method returns after this interface's work item has been serviced.

## Remarks

If a driver calls the **Flush** method, the method does not return until a worker thread has removed the specified work item from the work-item queue and called the driver's [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) callback function, and the *OnWorkItem* callback function has subsequently returned after processing the work item.

For more information, see [Using Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-workitems).

## See also

[IWDFWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfworkitem)

[OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function)