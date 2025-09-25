# ISyncMgrControl::UpdateEvents

## Description

Informs Sync Center that events have been added for a specific handler or item.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler that manages the item. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the item. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character. This parameter can be **NULL** if the event occurred on the handler rather than on a specific item.

### `nControlFlags` [in]

Type: **[SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags)**

A value from the [SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags) enumeration specifying whether the update should be performed synchronously or asynchronously.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If SYNCMGR_CF_WAIT is set in the *nControlFlags* parameter, **UpdateEvents** does not return until Sync Center has loaded the specified handler, retrieved the handler's event store, and reloaded all events from that store. If the handler is provided by a handler collection, the handler collection is also loaded to reload the handler.

#### Examples

The following example shows the usage of **ISyncMgrControl::UpdateEvents** by a handler's procedure.

```cpp
void CMyDeviceHandler::Synchronize(...)
{
    ...
    // Add events to the event store.

    // Get the Sync Center control object.
    ISyncMgrControl *pControl = NULL;

    hr = CoCreateInstance(CLSID_SyncMgrControl,
                          CLSCTX_SERVER,
                          IID_PPV_ARGS(&pControl));
    if (SUCCEEDED(hr))
    {
        // Tell Sync Center that we added events to our event store.
        // By passing NULL in pszItemID, we tell Sync Center that the event
        // occurred on the handler rather than a specific item.
        hr = pControl->UpdateEvents(s_szMyDeviceSyncHandlerID,
                                    NULL,
                                    SYNCMGR_CF_NOWAIT);
        pControl->Release();
    }

    ...

}

```