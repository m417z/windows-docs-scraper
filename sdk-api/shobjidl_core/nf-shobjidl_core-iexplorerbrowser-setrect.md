# IExplorerBrowser::SetRect

## Description

Sets the size and position of the view windows created by the browser.

## Parameters

### `phdwp` [in, out]

Type: **HDWP***

A pointer to a [DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos) handle. This parameter can be **NULL**.

### `rcBrowser` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The coordinates that the browser will occupy.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Coordinates are relative to the *hwndParent* passed in [IExplorerBrowser::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-initialize).