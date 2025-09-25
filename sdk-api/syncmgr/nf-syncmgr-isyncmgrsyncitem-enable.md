# ISyncMgrSyncItem::Enable

## Description

Enables or disables the sync item.

## Parameters

### `fEnable` [in]

Type: **BOOL**

**TRUE** to enable; **FALSE** to disable.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Sync Center calls this method in the following scenarios.

* When the user selects the item in the handler's folder and launches its **Enable** task, but only if the item has not set the [SYNCMGR_IPM_PREVENT_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) flag. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeEnable](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) object, this method is only called if the UI operation was successful.
* When the user selects the item in the handler's folder and launches its **Disable** task, but only if the item has not set the [SYNCMGR_IPM_PREVENT_DISABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) flag. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeDisable](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) object, this method is only called if the UI operation was successful.

If the handler does not need to perform any actions when it is activated, it can return either S_OK or E_NOTIMPL as shown in the example below.

#### Examples

The following example shows a simple implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::Enable(__in BOOL fEnable)
{
    return E_NOTIMPL;
}

```