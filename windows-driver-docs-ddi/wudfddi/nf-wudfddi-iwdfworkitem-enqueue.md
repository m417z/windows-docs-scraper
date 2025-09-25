# IWDFWorkItem::Enqueue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

 The **Enqueue** method adds this interface's framework work-item object to the system's work-item queue.

## Remarks

If your driver reuses its work-item objects, the driver can call **Enqueue** again for the same work item before a worker thread has removed the work item from the queue and called the driver’s [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) callback function.

 However, UMDF won't add the work item to the queue if it is already there. Therefore, your [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) callback function must process all queued work each time that it is called.

For more information, see [Using Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-workitems).

## See also

[IWDFWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfworkitem)

[OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function)