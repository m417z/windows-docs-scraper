# ISyncMgrSyncCallback::CanContinue

## Description

Determines whether the synchronization has been canceled.

## Parameters

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the ID of the item.

## Return value

Type: **HRESULT**

| Return Value | Meaning |
| --- | --- |
| S_OK | A cancellation has not been requested. The synchronization can continue. |
| S_FALSE | A cancellation has been requested. The handler should call [ISyncMgrSyncCallback::ReportProgress](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportprogress), specifying SYNCMGR_PS_CANCELED in the *nStatus* parameter. |
| E_INVALIDARG | The value pointed to by *pszItemID* is either unknown to Sync Center or is not an item managed by this handler. |

If *pszItemID* is **NULL** or an empty string, the return value depends on whether a cancellation has been requested for the entire handler.

## Remarks

A synchronization can be canceled by the user by clicking the **Stop** or **Stop All** task on the context menu or the command module. It can also be canceled when an application calls one of the stop methods of the [ISyncMgrControl](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrcontrol) interface.

By implementing this functionality as a separate method, the handler can check for a cancellation without reporting progress.

#### Examples

The following example shows the usage of **ISyncMgrSyncCallback::CanContinue** by the [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize) method.

```cpp
HRESULT CMyDeviceHandler::Synchronize(...)
{
    ...

    // Start synchronizing the sync items.

    ...

    // If a cancellation has been requested, stop the sync and exit.
    if (pCallback->CanContinue(pszItemID) == S_FALSE)
    {
        // End the sync operation and exit the function.
        hr = pCallback->ReportProgress(pszItemID,
                                       pszCancelMessage,
                                       SYNCMGR_PS_CANCELED,
                                       uCurrentStep,
                                       uMaxStep,
                                       NULL);
    }
    ...
}

```