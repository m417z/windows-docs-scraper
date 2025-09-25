# ISyncMgrHandler::Synchronize

## Description

Initiates a synchronization of a selection of the handler's sync items.

## Parameters

### `ppszItemIDs` [in]

Type: **LPCWSTR***

A pointer to an array of item IDs representing the items to be synchronized. Each item ID is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `cItems` [in]

Type: **ULONG**

The number of items in *ppszItemIDs*.

### `hwndOwner` [in]

Type: **HWND**

A handle to the window that the item uses to display any necessary UI. This value can be **NULL**.

### `pSessionCreator` [in]

Type: **[ISyncMgrSessionCreator](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsessioncreator)***

A pointer to an [ISyncMgrSessionCreator](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsessioncreator) interface. This interface enables the handler itself to report progress and events, or to signal a background process to report progress and events.

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an interface to be passed to [ISyncMgrControl](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrcontrol). **ISyncMgrHandler::Synchronize** is called either when a user requests a synchronization from the Sync Center folder or when one of the **ISyncMgrControl** synchronize methods is called, such as [StartSyncAll](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-startsyncall).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**ISyncMgrHandler::Synchronize** is called on its own thread. Sync Center instantiates the handler object and the session creator object on that thread and then calls this method.

The handler can create the session itself by calling the [CreateSession](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsessioncreator-createsession) method or it can signal an external process to perform the synchronization. If the handler creates the session, it should not return from the **ISyncMgrHandler::Synchronize** method until synchronization is complete. If the handler delegates synchronization to an external process, the external process should use [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create the CLSID_SyncMgrClient object, specifying the [ISyncMgrSessionCreator](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsessioncreator) interface. The process then creates the session so that it can report progress.

A user may elect to stop synchronization on an item or handler. An application can also stop synchronization by calling one of the stop methods on the [ISyncMgrControl](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrcontrol) interface, such as [StopItemSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-stopitemsync). The following mechanisms are provided to support these scenarios.

* [ReportProgress](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportprogress) returns a parameter indicating whether cancellation has been requested.
* The handler can call [CanContinue](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-cancontinue).

If the user asks to sync additional items after the **ISyncMgrHandler::Synchronize** method has been called, the handler can sync the new items in the same session by querying for them through the [QueryForAdditionalItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-queryforadditionalitems) method on the callback. If they choose to sync an item they queried for, they can then call [AddItemToSession](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-additemtosession).

Some handlers will not enumerate an item until it has been synchronized. If the handler discovers such items during a synchronization, it can inform Sync Center about them through the session. For example, if the handler discovers an item to add to the sync set, it calls [ProposeItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-proposeitem). Once the item has been successfully created, the handler calls [CommitItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-commititem). At that point, Sync Center adds it to the list of items that it is tracking for the handler.

The **ISyncMgrHandler::Synchronize** method is analogous to a combination of the older [PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) and [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) methods. In the case of the older interface, Sync Center called **PrepareForSync** immediately followed by **Synchronize**. The **ISyncMgrHandler::Synchronize** method provides the functionality of these two methods into a single call.

Another difference between **ISyncMgrHandler::Synchronize** and [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) is that the older method was expected to perform the synchronization asynchronously. **Synchronize** queued the request in one or more external threads and then returned. It then called [SynchronizeCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-synchronizecompleted) once it had finished synchronizing all items. **ISyncMgrHandler::Synchronize** supports a synchronous model for in-proc (foreground) synchronization or an asynchronous model for out-of-proc (background) synchronization.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::Synchronize(__in_ecount(cItems) LPCWSTR *ppszItemIDs,
                              __in ULONG                   cItems,
                              __in HWND                    hwndOwner,
                              __in ISyncMgrSessionCreator *pCreator,
                              __in_opt IUnknown           *punk)
{
    HRESULT hr = S_OK;

    // Create the session since we are going to perform synchronization in
    // this method.
    ISyncMgrSyncCallback *pCallback = NULL;

    hr = pCreator->CreateSession(_szHandlerID, ppszItemIDs, cItems,&pCallback);
    if (SUCCEEDED(hr))
    {
        for (ULONG iItem = 0; iItem < cItems; iItem++)
        {
            SYNCMGR_CANCEL_REQUEST nCancelRequest = SYNCMGR_CR_NONE;
            ULONG   uCurrentStep = 1;
            ULONG   cMaxSteps    = 50;
            LPCWSTR pszItemID    = ppszItemIDs[iItem];
            WCHAR   szProgressText[256];

            // Find the item.
            CMyDeviceSyncItem *pItem = NULL;

            // _FindItem is a private class function that abstracts the
            // specifics of how the handler has implemented its storage of
            // its items. Its internal details can remain transparent as
            // they have no bearing on this example.
            hr = _FindItem(pszItemID, &pItem);
            if (FAILED(hr))
            {
                // _ReportProgress is another private class function that loads
                // string resources so that reports can be localized rather
                // than use hard-coded strings. Its internal details have no
                // bearing on this example.
                _ReportProgress(pCallback,
                                pszItemID,
                                IDS_ITEM_NOTFOUND,
                                SYNCMGR_PS_FAILED,
                                0,
                                0,
                                &nCancelRequest);

                if (nCancelRequest != SYNCMGR_CR_NONE)
                {
                    break;
                }
                continue;
            }

            // Send the initial progress report to set min and max values.
            _ReportProgress(pCallback,
                            pszItemID,
                            IDS_START_ITEM_SYNC,
                            SYNCMGR_PS_UPDATING,
                            uCurrentStep,
                            cMaxSteps,
                            &nCancelRequest);

            for (; uCurrentStep < cMaxSteps; uCurrentStep++)
            {
                if (nCancelRequest != SYNCMGR_CR_NONE)
                {
                    break;
                }

                // Report progress.
                StringCchPrintfW(szProgressText,
                                 ARRAYSIZE(szProgressText),
                                 L"Entry %d of %d",
                                 uCurrentStep + 1,
                                 cMaxSteps);

                pCallback->ReportProgress(pszItemID,
                                          szProgressText,
                                          SYNCMGR_PS_UPDATING,
                                          uCurrentStep,
                                          cMaxSteps,
                                          &nCancelRequest);

                // The code that accomplishes the synchronization goes here.
                // This code depends entirely on the nature of the items
                // involved in the sync.
            }

            // Send the final progress report for this item.
            if (nCancelRequest != SYNCMGR_CR_NONE);
            {
                SYNCMGR_PROGRESS_STATUS nStatus = SYNCMGR_PS_SUCCEEDED;
                if (FAILED(hr))
                {
                    nStatus = SYNCMGR_PS_FAILED;
                }
                _ReportProgress(pCallback,
                                ppszItemIDs[iItem],
                                IDS_ITEM_SYNC_DONE,
                                nStatus,
                                uCurrentStep - 1,
                                cMaxSteps,
                                &nCancelRequest);
            }

            hr = S_OK;

            if (nCancelRequest == SYNCMGR_CR_CANCEL_ALL)
            {
                 break;
            }
        }

        pCallback->Release();
    }

    return hr;
}

```