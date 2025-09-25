# ISyncMgrSyncItem::GetCapabilities

## Description

Gets a set of flags describing the item's defined capabilities.

## Parameters

### `pmCapabilities` [out]

Type: **[SYNCMGR_ITEM_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities)***

When this method returns, contains a pointer to a bitwise combination of values from the [SYNCMGR_ITEM_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) enumeration that defines the capabilities of the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by Sync Center in response to a call to [UpdateItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updateitem).

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::GetCapabilities(
                              __out SYNCMGR_ITEM_CAPABILITIES *pmCapabilities)
{
    *pmCapabilities = SYNCMGR_ICM_EVENT_STORE
                    | SYNCMGR_ICM_CAN_DELETE
                    | SYNCMGR_ICM_QUERY_BEFORE_DELETE;

    return S_OK;
}

```