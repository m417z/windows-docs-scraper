# ISyncMgrControl::UpdateHandlerCollection

## Description

Instructs Sync Center to reenumerate the handler collection, or informs it that properties of a handler in the handler collection have changed.

## Parameters

### `rclsidCollectionID` [in]

Type: **REFCLSID**

A reference to the handler collection's CLSID.

### `nControlFlags` [in]

Type: **[SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags)**

A value from the [SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags) enumeration specifying whether the update should be performed synchronously or asynchronously.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If SYNCMGR_CF_WAIT is set in the *nControlFlags* parameter, **UpdateHandlerCollection** does not return until Sync Center has loaded the specified handler collection and reloaded all handler and item information.

#### Examples

The following example shows the usage of **ISyncMgrControl::UpdateHandlerCollection** by a handler's procedure.

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
        // Tell Sync Center that a new computer has been added.
        hr = pControl->UpdateHandlerCollection(CLSID_FRSHandlerCollection,
                                               SYNCMGR_CF_NOWAIT);
        pControl->Release();
    }

    ...

}

```