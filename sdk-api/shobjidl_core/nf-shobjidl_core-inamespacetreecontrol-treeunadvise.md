# INameSpaceTreeControl::TreeUnadvise

## Description

Enables a client to unregister with the control.

## Parameters

### `dwCookie` [in]

Type: **DWORD***

A pointer to the cookie that is to be unregistered.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The pointer to the cookie that is passed in is the one that was passed back in [INameSpaceTreeControl::TreeAdvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacetreecontrol-treeadvise).