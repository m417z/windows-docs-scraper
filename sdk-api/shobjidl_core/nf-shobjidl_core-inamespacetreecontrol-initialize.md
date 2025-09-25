# INameSpaceTreeControl::Initialize

## Description

Initializes an [INameSpaceTreeControl](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacetreecontrol) object.

## Parameters

### `hwndParent` [in]

Type: **HWND**

The handle of the parent window.

### `prc` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the size and position of the control in the client window.

### `nsctsFlags` [in]

Type: **[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)**

The characteristics of the given namespace tree control. One or more of the following values from the [NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.