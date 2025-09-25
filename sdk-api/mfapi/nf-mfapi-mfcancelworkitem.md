# MFCancelWorkItem function

## Description

Attempts to cancel an asynchronous operation that was scheduled with [MFScheduleWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfscheduleworkitem) or [MFScheduleWorkItemEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfscheduleworkitemex).

## Parameters

### `Key` [in]

The key that was received in the *pKey* parameter of the [MFScheduleWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfscheduleworkitem), [MFScheduleWorkItemEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfscheduleworkitemex), or [MFPutWaitingWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputwaitingworkitem) functions.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Because work items are asynchronous, the work-item callback might still be invoked after **MFCancelWorkItem** is called.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)