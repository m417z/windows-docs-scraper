# ISyncMgrSyncItem::GetPolicies

## Description

Gets a set of flags describing the policies set by the item.

## Parameters

### `pmPolicies` [out]

Type: **[SYNCMGR_ITEM_POLICIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_policies)***

When this method returns, contains a pointer to a bitwise combination of values from the [SYNCMGR_ITEM_POLICIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_policies) enumeration that defines the item's policies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A policy is an action that is typically supported but can be disabled by a group policy.

This method is called by Sync Center in response to a call to [UpdateItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updateitem).

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::GetPolicies(
                              __out SYNCMGR_ITEM_POLICIES *pmPolicies)
{
    *pmPolicies = SYNCMGR_IPM_PREVENT_DISABLE
                | SYNCMGR_IPM_HIDDEN_BY_DEFAULT;

    return S_OK;
}

```