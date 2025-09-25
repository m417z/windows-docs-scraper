# ISyncMgrControl::EnableItem

## Description

Enables or disables a sync item managed by a specified handler.

## Parameters

### `fEnable` [in]

Type: **BOOL**

**TRUE** to enable; **FALSE** to disable.

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the item. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `hwndOwner` [in]

Type: **HWND**

A handle to a window that can be used by the item to display any necessary UI. This value can be **NULL**.

### `nControlFlags` [in]

Type: **[SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags)**

A value from the [SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags) enumeration specifying whether the enabling or disabling of the item should be performed synchronously or asynchronously.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An *enabled* item is an item that can be synchronized.

If the specified item returns [SYNCMGR_ICM_QUERY_BEFORE_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) or [SYNCMGR_ICM_QUERY_BEFORE_DISABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) in the mask returned from the [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities) method, the user is presented with a confirmation dialog box requested before the item is enabled or disabled. If no query UI is requested or once the user confirms the operation, the item's [Enable](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-enable) method is called.

If SYNCMGR_CF_WAIT is set in the *nControlFlags* parameter, **EnableItem** does not return until Sync Center has processed this notification.

#### Examples

The following example shows the usage of [ISyncMgrControl::EnableHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-enablehandler) by a handler's procedure.

```cpp
void MiscProc(...)
{
    ...

    // Get the Sync Center control object.
    ISyncMgrControl *pControl = NULL;

    hr = CoCreateInstance(CLSID_SyncMgrControl,
                          CLSCTX_SERVER,
                          IID_PPV_ARGS(&pControl));
    if (SUCCEEDED(hr))
    {
        // Tell Sync Center to disable the item.
        hr = pControl->EnableItem(FALSE,
                                  s_szMySyncHandlerID,
                                  s_szMySyncHandlerMusicContentID,
                                  hwnd,
                                  SYNCMGR_CF_WAIT);
        pControl->Release();
    }

    ...

}

```