# ISyncMgrUIOperation::Run

## Description

Performs the actual display of UI for a handler or sync item when requested to do so by Sync Center.

## Parameters

### `hwndOwner` [in]

Type: **HWND**

A handle to the window used to display the UI.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns S_FALSE or another error code if this method is called to confirm an operation, such as activating a handler or disabling a sync item, but that operation should not be executed.

## Remarks

The handler itself, not the UI, is expected to use the [ISyncMgrControl](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrcontrol) interface to notify Sync Center of changes to its state that come about through choices made by the user in the UI.

#### Examples

The following example shows the outline of an implementation of this method. In this case, the implementation is that which would be returned when [GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) is called with the SYNCMGR_OBJECTID_QueryBeforeDelete object ID.

```cpp
STDMETHODIMP CQueryBeforeDelete::Run(__in HWND hwndOwner)
{
    HRESULT hr = S_OK;

    // Display a dialog confirming that the user wants to delete the item.

    return hr;
}

```