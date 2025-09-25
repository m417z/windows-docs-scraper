# INameSpaceTreeControl::TreeAdvise

## Description

Enables a client to register with the control.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the client IUnknown that registers with the control.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to the cookie that is passed back for registration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The pointer to the cookie that is passed back is used to unregister the control later with [INameSpaceTreeControl::TreeUnadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacetreecontrol-treeunadvise).