# ISyncMgrSyncCallback::ReportProgress

## Description

Reports the progress of the synchronization of a single sync item to Sync Center.

## Parameters

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the item currently being synchronized. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `pszProgressText` [in]

Type: **LPCWSTR**

A pointer to a buffer containing a Unicode string for any custom progress messaging for this item.

### `nStatus` [in]

Type: **[SYNCMGR_PROGRESS_STATUS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status)**

A value from the [SYNCMGR_PROGRESS_STATUS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status) enumeration stating the current progress status of the synchronization.

### `uCurrentStep` [in]

Type: **ULONG**

The current step in the synchronization. If the [SYNCMGR_PS_UPDATING_INDETERMINATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status) flag is set in *nStatus*, this parameter is ignored.

### `uMaxStep` [in]

Type: **ULONG**

The total number of steps required to complete the synchronization of the item. If the [SYNCMGR_PS_UPDATING_INDETERMINATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status) flag is set in *nStatus*, this parameter is ignored.

### `pnCancelRequest` [out]

Type: **[SYNCMGR_CANCEL_REQUEST](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_cancel_request)***

When this method returns, points to a value from the [SYNCMGR_CANCEL_REQUEST](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_cancel_request) enumeration specifying the nature of a cancel request, if any.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you want to report progress on the handler rather than individual sync items, call [ISyncMgrSyncCallback::SetHandlerProgressText](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-sethandlerprogresstext).

If the synchronization has been canceled, the handler calls **ISyncMgrSyncCallback::ReportProgress** on the item one final time, acknowledging the cancellation request by specifying [SYNCMGR_PS_CANCELED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status) in the *nStatus* parameter. This updates the UI and also allows the user to restart a sync for that item.

Once this method reports a completion status ([SYNCMGR_PS_SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status), [SYNCMGR_PS_FAILED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status), or [SYNCMGR_PS_CANCELED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status)), the only further status report that can be made is [SYNCMGR_PS_FAILED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status). Any other value causes this method to return E_ACCESSDENIED and Sync Center to mark the item as failed.

This method replaces [Progress](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-progress).

The maximum length of a progress string is MAX_SYNCMGR_PROGRESSTEXT. This constant is defined in SyncMgr.h.

#### Examples

The following example shows the usage of **ISyncMgrSyncCallback::ReportProgress** by the [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize) method.

```cpp
STDMETHODIMP CMyDeviceHandler::Synchronize(...)
{
    ...

    // Start synchronizing the sync item.

    ...

    // Construct a string to display in the Sync Center folder.
    // Report the progress to Sync Center.
    SYNCMGR_CANCEL_REQUEST nCancelRequest;
    hr = pCallback->ReportProgress(pszItemID,
                                   pszProgressText,
                                   SYNCMGR_PS_UPDATING,
                                   uCurrentStep,
                                   uMaxStep,
                                   &nCancelRequest);
    if (SUCCEEDED(hr))
    {
        if (nCancelRequest != SYNCMGR_CR_NONE)
        {
            // Synchronization was canceled.
            hr = pCallback->ReportProgress(pszItemID,
                                           pszProgressText,
                                           SYNCMGR_PS_CANCELED,
                                           uCurrentStep,
                                           uMaxStep,
                                           NULL);
        }
    }
    ...
}

```