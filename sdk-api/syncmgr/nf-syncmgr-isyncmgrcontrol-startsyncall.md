# ISyncMgrControl::StartSyncAll

## Description

Synchronizes all items managed by all handlers.

## Parameters

### `hwndOwner` [in]

Type: **HWND**

A handle to a window that can be used by a handler or item to display any necessary UI. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is analogous to [UpdateAll](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizeinvoke-updateall).

#### Examples

The following example shows the usage of **ISyncMgrControl::StartSyncAll** by a handler's procedure.

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
        // Synchronize all sync items for all sync handlers.
        hr = pControl->StartSyncAll(_hwnd);
        pControl->Release();
    }

    ...

}

```