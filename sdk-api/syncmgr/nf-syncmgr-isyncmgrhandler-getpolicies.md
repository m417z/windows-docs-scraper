# ISyncMgrHandler::GetPolicies

## Description

Gets a set of flags describing the policies set by the handler.

## Parameters

### `pmPolicies` [out]

Type: **[SYNCMGR_HANDLER_POLICIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies)***

When this method returns, contains a pointer to a bitwise combination of values from the [SYNCMGR_HANDLER_POLICIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) enumeration that define the handler's policies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A policy is an action that is usually supported but can be disabled by a group policy.

This method is called by Sync Center in response to a call to [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) or [UpdateHandlerCollection](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandlercollection).

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetPolicies(
                             __out SYNCMGR_HANDLER_POLICIES *pmPolicies)
{
    *pmPolicies = SYNCMGR_HPM_NONE;
    return S_OK;
}

```