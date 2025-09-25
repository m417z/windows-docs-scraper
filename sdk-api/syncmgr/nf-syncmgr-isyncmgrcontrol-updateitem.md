# ISyncMgrControl::UpdateItem

## Description

Informs Sync Center that properties of a sync item have changed.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler that manages the item. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the item. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `nControlFlags` [in]

Type: **[SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags)**

A value from the [SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags) enumeration specifying whether the update should be performed synchronously or asynchronously.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If SYNCMGR_CF_WAIT is set in the *nControlFlags* parameter, **UpdateItem** does not return until Sync Center has loaded the specified handler and reloaded all handler and item information. If the handler is provided by a handler collection, the handler collection is also loaded to reload the handler.

#### Examples

The following example shows the usage of **ISyncMgrControl::UpdateItem** by a handler's procedure.

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
        // Tell Sync Center that properties of the item have changed.
        hr = pControl->UpdateItem(s_szMySyncHandlerID,
                                  s_szMySyncHandlerMusicContentID,
                                  SYNCMGR_CF_WAIT);
        pControl->Release();
    }

    ...

}

```