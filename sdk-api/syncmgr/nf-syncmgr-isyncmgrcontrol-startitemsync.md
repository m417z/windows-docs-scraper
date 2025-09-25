# ISyncMgrControl::StartItemSync

## Description

Initiates the synchronization of specified items managed by a particular handler.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler that manages the items. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `ppszItemIDs` [in]

Type: **LPCWSTR***

The address of a pointer to a buffer containing an array of IDs of the items to be synchronized. Each ID is of maximum length MAX_SYNCMGR_ID including the terminating **null** character. This array is passed to [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize).

### `cItems` [in]

Type: **DWORD**

The number of IDs in *ppszItemIDs*.

### `hwndOwner` [in]

Type: **HWND**

A handle to the window that the item can use to display any necessary UI. This value can be **NULL**.

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) to be passed to [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize). This parameter can be **NULL**.

### `nSyncControlFlags` [in]

Type: **[SYNCMGR_SYNC_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_sync_control_flags)**

A member of the [SYNCMGR_SYNC_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_sync_control_flags) enumeration that specifies whether an item found in both a current sync and a queued sync should be synchronized again when the queued sync is performed.

### `pResult` [in]

Type: **[ISyncMgrSyncResult](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncresult)***

A pointer to an instance of [ISyncMgrSyncResult](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncresult), whose [Result](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncresult-result) method is called when the synchronization ends, either through success, failure, or cancellation. The **Result** method is called with the aggregated state of the handler synchronization. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is analogous to [UpdateItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizeinvoke-updateitems).

#### Examples

The following example shows the usage of **ISyncMgrControl::StartItemSync** by a handler's procedure.

```cpp
void CMyDeviceHandler::MiscProc(...)
{
    ...

    // Get the Sync Center control object.
    ISyncMgrControl *pControl = NULL;

    hr = CoCreateInstance(CLSID_SyncMgrControl,
                          CLSCTX_SERVER,
                          IID_PPV_ARGS(&pControl));
    if (SUCCEEDED(hr))
    {
        // Synchronize one sync item for the sync handler.
        hr = pControl->StartItemSync(s_szMySyncHandlerID,
                                     s_szMySyncHandlerMusicContentID,
                                     1,
                                     _hwnd,
                                     NULL,
                                     NULL);
        pControl->Release();
    }

    ...

}

```